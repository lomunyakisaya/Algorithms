# Python WebSockets Notes

## 1. What is a WebSocket?
A WebSocket is a communication protocol that provides a persistent, two-way connection between a client and a server.

Unlike HTTP, where the client sends a request and the server replies once, WebSockets allow:
- continuous communication
- real-time updates
- instant sending and receiving of messages

WebSockets are commonly used in:
- chat apps
- live notifications
- online games
- dashboards
- stock market apps
- collaborative tools

---

## 2. WebSocket vs HTTP

### HTTP
- request-response model
- connection closes after each response
- good for normal web pages and APIs

### WebSocket
- keeps a persistent connection open
- supports full-duplex communication
- both sides can send data anytime

Example comparison:

```text
HTTP: Client -> Server -> Response -> Close
WebSocket: Client <-> Server (continuous connection)
```

---

## 3. Why use WebSockets?
WebSockets are useful when you need:
- live data updates
- real-time communication
- instant messaging
- notifications
- multiplayer communication

They are better than repeatedly polling the server for updates.

---

## 4. Python WebSocket libraries
The most common library is:
pip
```bash
pip install websockets
```

This library lets you create WebSocket clients and servers in Python.

---

## 5. Basic WebSocket server example
```python
import asyncio
import websockets

async def hello(websocket):
    print("Client connected")

    async for message in websocket:
        print(f"Received: {message}")
        await websocket.send(f"Server echo: {message}")

async def main():
    async with websockets.serve(hello, "localhost", 8765):
        print("Server started on ws://localhost:8765")
        await asyncio.Future()  # keep server running

asyncio.run(main())
```

### Explanation
- `websockets.serve()` starts the server
- `localhost` is the host
- `8765` is the port
- `websocket.send()` sends data back to the client
- `async for message in websocket` listens for incoming messages

---

## 6. Basic WebSocket client example
```python
import asyncio
import websockets

async def client():
    async with websockets.connect("ws://localhost:8765") as websocket:
        await websocket.send("Hello Server")
        response = await websocket.recv()
        print("Response:", response)

asyncio.run(client())
```

### Output
```text
Response: Server echo: Hello Server
```

---

## 7. How WebSockets work
A WebSocket connection starts with a handshake.

1. Client opens a connection to the server.
2. Server accepts the upgrade from HTTP to WebSocket.
3. A persistent connection is established.
4. Messages can be exchanged continuously.
5. Connection can be closed when done.

---

## 8. Important WebSocket terms

### Client
The program that connects to the server.

### Server
The program that listens for incoming client connections.

### Message
The piece of data sent between client and server.

### Handshake
The initial connection setup between client and server.

### Full-duplex
Both sides can send and receive data at the same time.

---

## 9. When to use WebSockets
Use WebSockets when you need:
- live chat systems
- real-time notifications
- multiplayer gaming
- tracking stock prices
- IoT device communication
- real-time collaboration apps

---

## 10. WebSockets in real life
Examples:
- WhatsApp live chat
- Slack notifications
- online gaming servers
- live sports score updates
- sensor monitoring dashboards

---

## 11. Simple echo server explanation
An echo server sends back the message it receives.

This helps to understand how WebSocket communication works.

```python
import asyncio
import websockets

async def echo(websocket):
    async for msg in websocket:
        await websocket.send(msg)

async def main():
    async with websockets.serve(echo, "localhost", 9000):
        await asyncio.Future()

asyncio.run(main())
```

The server simply sends the same message back to the client.

---

## 12. Common WebSocket methods
Some important methods in Python `websockets`:

- `websockets.connect()` - connect to a WebSocket server
- `websockets.serve()` - start a WebSocket server
- `send()` - send a message
- `recv()` - receive a message
- `async for` - read incoming messages in a loop

---

## 13. Key advantages
- real-time communication
- lower overhead than repeated HTTP requests
- efficient for streaming data
- supports frequent updates

---

## 14. Limitations
- not ideal for simple one-time requests
- requires a server that supports WebSockets
- more complex than HTTP for basic tasks

---

## 15. Summary
WebSockets are used for real-time, two-way communication between a client and a server.

Key points:
- they keep the connection open
- they are faster for live updates
- Python can use the `websockets` library
- they are widely used in chat and live apps

---

## 16. Quick revision questions
1. What is a WebSocket?
2. How is it different from HTTP?
3. Why are WebSockets useful for real-time apps?
4. Which Python library is commonly used for WebSockets?
5. What does `send()` do in a WebSocket connection?

---

## 17. Final note
If you are learning Python networking, start with simple WebSocket examples like an echo server and then move to chat apps or live dashboards. This helps you understand real-time client-server communication clearly.
