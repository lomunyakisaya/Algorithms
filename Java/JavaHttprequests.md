# Java HTTP Requests

## 1. The modern Java HTTP API

For new code, use `java.net.http.HttpClient`, `HttpRequest`, and
`HttpResponse`. They became part of the Java standard library in Java 11, so
no third-party HTTP library is required for basic requests.

The request/response flow is:

1. Create or reuse an `HttpClient`.
2. Build an `HttpRequest` with a URI, method, headers, timeout, and optional
   body.
3. Send it with `client.send(...)` for a synchronous request or
   `client.sendAsync(...)` for an asynchronous request.
4. Inspect the response status, headers, and body.

The client handles the underlying connection work, including HTTP protocol
details and TLS for HTTPS URLs.

## 2. Imports and a simple GET

```java
import java.io.IOException;
import java.net.URI;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;
import java.time.Duration;

public class HttpGetExample {
    public static void main(String[] args)
            throws IOException, InterruptedException {
        HttpClient client = HttpClient.newHttpClient();

        HttpRequest request = HttpRequest.newBuilder()
                .uri(URI.create("https://example.com/"))
                .timeout(Duration.ofSeconds(10))
                .GET()
                .build();

        HttpResponse<String> response =
                client.send(request, HttpResponse.BodyHandlers.ofString());

        System.out.println("Status: " + response.statusCode());
        System.out.println("Body: " + response.body());
    }
}
```

`HttpRequest.newBuilder()` creates a builder. Calling `build()` creates the
immutable request. `HttpClient.newHttpClient()` is a convenient default
client; for configuration, create one with `HttpClient.newBuilder()`.

## 3. Reuse and configure the client

Create a client once and reuse it for multiple requests. A client manages
connection resources and can be shared across threads; repeatedly creating a
new client is usually unnecessary.

```java
HttpClient client = HttpClient.newBuilder()
        .connectTimeout(Duration.ofSeconds(5))
        .followRedirects(HttpClient.Redirect.NORMAL)
        .build();
```

Common client settings:

- `connectTimeout(...)` limits how long the client waits to establish a
  connection. It is not the full-request timeout.
- `followRedirects(...)` controls whether and how redirects are followed.
  The default is `NEVER`; `NORMAL` follows common redirects but not HTTPS to
  HTTP redirects.
- `version(...)` can request HTTP/1.1 or HTTP/2. The server and connection
  determine what is actually negotiated.
- `proxy(...)`, `authenticator(...)`, and `cookieHandler(...)` configure
  those behaviors when the application needs them. Cookies are not
  automatically persisted by a default client.

Use the per-request `timeout(...)` as well when the whole operation must have
a deadline:

```java
HttpRequest request = HttpRequest.newBuilder(uri)
        .timeout(Duration.ofSeconds(15))
        .GET()
        .build();
```

## 4. HTTP methods and request bodies

The builder has convenience methods such as `.GET()` and `.POST(publisher)`.
Use `.method(name, publisher)` for methods without a convenience method, such
as `PATCH`.

```java
HttpRequest post = HttpRequest.newBuilder(uri)
        .header("Content-Type", "text/plain; charset=UTF-8")
        .POST(HttpRequest.BodyPublishers.ofString("Hello"))
        .build();

HttpRequest put = HttpRequest.newBuilder(uri)
        .PUT(HttpRequest.BodyPublishers.ofString("replacement"))
        .build();

HttpRequest patch = HttpRequest.newBuilder(uri)
        .method("PATCH", HttpRequest.BodyPublishers.ofString("partial update"))
        .build();

HttpRequest delete = HttpRequest.newBuilder(uri)
        .DELETE()
        .build();
```

`BodyPublishers.noBody()` is useful for methods that need an explicitly empty
body. A GET request normally has no body. Common body publishers include:

- `ofString(...)` for text or JSON.
- `ofByteArray(...)` for bytes already in memory.
- `ofFile(...)` for a file.
- `noBody()` for an empty body.

Use the publisher that matches the data size and source. Reading a large file
into a byte array just to send it can waste memory.

## 5. Sending JSON

Set `Content-Type` to describe the body being sent, and use `Accept` to state
which response representation the client prefers.

```java
String json = "{\"name\":\"Ada\",\"active\":true}";

HttpRequest request = HttpRequest.newBuilder()
        .uri(URI.create("https://api.example.com/users"))
        .header("Content-Type", "application/json; charset=UTF-8")
        .header("Accept", "application/json")
        .POST(HttpRequest.BodyPublishers.ofString(json))
        .build();

HttpResponse<String> response =
        client.send(request, HttpResponse.BodyHandlers.ofString());
```

The example uses a fixed string for clarity. For values from users or other
dynamic data, use a JSON library such as Jackson or Gson to serialize an
object. Do not construct JSON by concatenating untrusted values: quotes,
backslashes, and other special characters must be escaped correctly.

## 6. Query parameters and URI encoding

Query parameter values must be encoded before adding them to a URI. For
form-style query encoding, Java provides `URLEncoder`:

```java
import java.net.URLEncoder;
import java.nio.charset.StandardCharsets;

String searchTerm = "Java HTTP";
String encodedTerm =
        URLEncoder.encode(searchTerm, StandardCharsets.UTF_8);
URI uri = URI.create(
        "https://api.example.com/search?q=" + encodedTerm);
```

Encode each parameter value, not the entire URI. For multiple parameters,
encode each value separately and join them with `&`. `URLEncoder` is intended
for form encoding; path segments have different encoding rules, so do not use
it as a general-purpose path encoder. Avoid putting secrets in query
parameters because URLs are often recorded in logs and history.

## 7. Reading the response

`HttpResponse<T>` contains the response metadata and a body of type `T`.
`BodyHandlers` determines how the body is consumed:

- `ofString()` reads text into a `String`.
- `ofByteArray()` reads the entire body into a byte array.
- `ofFile(path)` writes the body to a file.
- `discarding()` ignores the body.
- `ofInputStream()` exposes a stream; close it when finished.

Example response inspection:

```java
int status = response.statusCode();
String contentType =
        response.headers().firstValue("Content-Type").orElse("(missing)");
String body = response.body();
```

Choose a body handler based on the expected response size. `ofString()` and
`ofByteArray()` keep the full response in memory. For large downloads, use
`ofFile()` or stream the body and close the stream.

## 8. HTTP errors versus request failures

An HTTP response with status `404` or `500` is still a successfully received
HTTP response. `client.send(...)` does not throw just because the server
returned a non-2xx status. Check `statusCode()` and decide what the
application should do:

```java
if (response.statusCode() >= 200 && response.statusCode() < 300) {
    System.out.println("Request succeeded");
} else {
    System.err.println("Server returned HTTP " + response.statusCode());
    System.err.println(response.body());
}
```

By contrast, connection problems and other I/O failures are reported as
exceptions. A synchronous `send(...)` can throw:

- `IOException` for I/O or connection failures.
- `InterruptedException` if the waiting thread is interrupted.

If you catch `InterruptedException`, restore the interrupt flag unless your
method propagates it:

```java
try {
    HttpResponse<String> response =
            client.send(request, HttpResponse.BodyHandlers.ofString());
} catch (InterruptedException e) {
    Thread.currentThread().interrupt();
    throw new IOException("HTTP request was interrupted", e);
}
```

Do not silently treat an exception or an error status as a successful empty
response. Surface enough information for the caller to handle the failure,
while avoiding logging credentials or sensitive response data.

## 9. Asynchronous requests

`sendAsync(...)` returns a `CompletableFuture`. It lets the calling thread
continue without waiting for the response:

```java
CompletableFuture<HttpResponse<String>> future =
        client.sendAsync(request, HttpResponse.BodyHandlers.ofString());

future.whenComplete((response, error) -> {
    if (error != null) {
        System.err.println("Request failed: " + error.getMessage());
        return;
    }

    System.out.println("Status: " + response.statusCode());
    System.out.println("Body: " + response.body());
});
```

Import `java.util.concurrent.CompletableFuture` for this example. An
asynchronous future can fail exceptionally for connection errors, timeouts,
or cancellation. HTTP error statuses still arrive as ordinary responses and
must be checked separately. Avoid calling `.join()` immediately if the goal
is to keep the request non-blocking; `join()` waits and wraps failures in a
`CompletionException`.

Use `thenApply`, `thenCompose`, and related methods to transform or chain
asynchronous work. Keep callbacks short; use an appropriate executor for
blocking or CPU-heavy work rather than blocking a callback thread.

## 10. Headers and authentication

Headers provide metadata about the request. Common examples include:

- `Accept`: response formats the client can process.
- `Content-Type`: format of the request body.
- `Authorization`: credentials or a token.
- `User-Agent`: identifies the client application.

Set headers with `.header(name, value)`:

```java
HttpRequest request = HttpRequest.newBuilder(uri)
        .header("Accept", "application/json")
        .header("Authorization", "Bearer " + accessToken)
        .GET()
        .build();
```

Treat tokens, passwords, and other credentials as secrets: do not hard-code
them, print them, commit them, or send them to an untrusted host. Use HTTPS
for sensitive data. Keep normal TLS certificate and hostname validation
enabled; do not install a permissive trust manager to make a connection
"work."

## 11. Retries and reliability

Retries can help with transient failures, but retrying every request
unconditionally can duplicate work or overload a service.

- GET and other idempotent operations are generally safer to retry than
  operations that create or charge something.
- A timeout does not prove that the server did not process the request; it
  may have completed the operation but the response was lost.
- Use a bounded retry count, a delay/backoff policy, and any server-provided
  retry guidance.
- For operations that must not be duplicated, use an API-supported
  idempotency key or another server-side deduplication mechanism.
- Distinguish an HTTP status that the API documents as retryable from
  validation, authorization, and other failures that will not improve by
  retrying.

## 12. Quick checklist

- Use Java 11 or newer and `java.net.http.HttpClient` for the standard
  library HTTP API.
- Reuse a configured `HttpClient`; set connection and request timeouts.
- Build URIs carefully and encode query parameter values.
- Set appropriate `Accept` and `Content-Type` headers.
- Use a JSON serializer for dynamic JSON data.
- Check the HTTP status code; non-2xx statuses are not thrown as exceptions.
- Choose a body handler appropriate for the response size and close streams.
- Handle I/O errors and interruption explicitly.
- Keep secrets out of source, URLs, logs, and untrusted destinations.
- Retry only when the operation and failure are safe to retry.