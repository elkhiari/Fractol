# Fractol

#### **requirement :**

* struct
* minilibx
* complex number

## 1.Struct (Structure):

A struct (short for structure) is a user-defined data type in many programming languages, including C/C++. It allows you to group multiple variables of different types into a single unit. The variables inside a struct are called members, and they can have various data types, including primitive types (like int, char, float) or even other structs. struct provides a way to create custom data types, making it easier to organize and manage related data.

    struct s_Person {
        char name[50];
        int age;
        float height;
    };


    typedef struct {
        char name[50];
        int age;
        float height;
    } t_Person;


    typedef struct s_Person {
        char name[50];
        int age;
        float height;
    } t_Person;


    int main()
    {
        t_Person person1;
        struct s_Person person2;

        person1.age = 19;
        person2.age = 25;

        printf("Person1 age: %d\n", person1.age);
        printf("Person2 age: %d\n", person2.age);
    }
