public class Student{
    Student (String first_name, String last_name, int regNo, int age, String course){
        this.first_name = first_name;
        this.last_name = last_name;
        this.regNo = regNo;
        this.age = age;
        this.course = course;
    }
    String first_name;
    String last_name;
    int regNo;
    int age;
    String course;
    void display(){
        System.out.println("First Name: " + first_name);
        System.out.println("Last Name: " + last_name);
        System.out.println("Registration Number: " + regNo);
        System.out.println("Age: " + age);
        System.out.println("Course Name: " + course);
    }
}