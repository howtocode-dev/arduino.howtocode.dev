গত পর্বে আমরা দেখেছিলাম ক্লাস ডিফাইন করে কিভাবে, অবজেক্ট তৈরি করে কিভাবে, অবজেক্ট এর মেথড, অ্যাট্রিবিউট সেট করা এবং তা `Call` করা। আজকে আমরা বেশ কিছু জিনিস সংক্ষিপ্ত আকারে দেখব।
আজকে যা আলোচনা করা হবে:

*    Encapsulation
*    Constructor
*    Inheritance
*    Polymorphism

## Encapsulation:

এর অপর নাম `Data hiding` বা `Data protection`। `OOP` এর একটি জনপ্রিয় ফিচার এবং সফটওয়্যার ডিজাইন ও বিল্ডিংয়ের জন্যও গুরুত্বপূর্ণ। সফটওয়্যার ব্যবহারকারীর জানার দরকার নেই সফটওয়্যারটি কীভাবে কাজ করে (যারা নন ডেভলপার) কাজ চললেই এবং মনমত পার্ফর্মেন্স পেলেই হল। সেদিক থেকে `Encapsulation` খুবই জরুরি। কোন ক্লাসের Attribute গুলোকে সাধারণত আমরা `Encapsulated` করে থাকি। আমরা আগেই দেখেছি Object এর Attribute পরিবর্তন করা কোন ব্যাপার না। ধরা যাক, Person একটি Class যার Attribute গুলো হল `name (string type)` এবং `age (int type)`।তাহলে আমরা Person এর একটা object তৈরি করে সহজেই তার নাম পরিবর্তন করতে পারি:

```cpp	
#include <iostream>
using namespace std;
 
class Person
{
public:
    string name;
    int age;
};
 
int main()
{
    Person idiot;
    idiot.age = 0;
    idiot.name = "Idiot";
    cout << idiot.age << endl;
    cout << idiot.name << endl;
}
```
উপরের কোডটি ঠিকঠাক চলবে কিন্তু নিচেরটা চলবেই না। পরিবর্তন কোথায়? `public` এর বদলে `private` বসিয়েছি :)

```cpp	
#include <iostream>
using namespace std;
 
class Person
{
private:
    string name;
    int age;
};
 
int main()
{
    Person idiot;
    idiot.age = 0;
    idiot.name = "Idiot";
    cout << idiot.age << endl;
    cout << idiot.name << endl;
}
```

তারমানে এভাবে আমরা `Class` কে `Encapsulated` করলাম! আর এতে সুবিধা হল ইউজার ডিরেক্টলি তার `Attribute` এ অ্যাক্সেস পেল না।

এখানে আরেকটি গুরুত্বপূর্ণ ব্যাপার, যদি আমরা `Attribute` এ অ্যাক্সেস না পাই তাহলে সেটা দিয়ে আমাদের কি লাভ? এখানে আবার `OOP` সর্বোপরি `C++` এর চমক। `Private` বা `Protected` ডেটা আমরা ডিরেক্টলি অ্যাক্সেস করতে পারি না বটে, কিন্তু আমরা `public` ফাংশনের মাধ্যমে `private` ডেটায় অ্যাক্সেস পেতে পারি! তার মানে হল, আমার ক্লাসে যদি একটি পাব্লিক মেম্বার ফাংশন থাকে এবং সেটা এমন একটি `Attribute` নিয়ে Deal করে যেটা কিনা `Private/Protected` তারপরও আমরা ঔ `Attribute` এ অ্যাক্সেস পাব। নিচের উদাহরণটি দেখা যাক:
```cpp
#include <iostream>
using namespace std;
 
class Person
{
public:
    void setNameAndAge(string n, int a);
    void showNameAndAge();
private:
    string name;
    int age;
};
 
int main()
{
    Person A;
    A.setNameAndAge("My Name", 20);
    A.showNameAndAge();
}
 
void Person::setNameAndAge(string n, int a)
{
    name = n;
    age = a;
}
 
void Person::showNameAndAge()
{
    cout << "The name: " << name << endl;
    cout << "The age: " << age << endl;
}
```

`setNameAndAge` এবং `showNameAndAge` দুইটা যেহেতু পাব্লিক তাই আমরা `Object` দ্বারা ডিরেক্টলি অ্যাক্সেস পাচ্ছি।আবার যেহেতু এই দুইটি মেথড ঔ ক্লাসের মধ্যে অবস্থিত তাই ঔ মেথডগুলো নিজের ক্লাসের সকল `Private/Public/Protected Attribute` গুলোতে অ্যাক্সেস পাবে। এখানে ব্যাপারটা ঠিক “কান টানলে মাথা আসে” মাথা প্রাইভেট তাই আমরা ডিরেক্টলি মাথা টানতে পারব না, আমাদের হাতে যেহেতু কান আছে `(setNameAndAge এবং showNameAndAge)` তাই ঔটা দিয়েই টানতে পারব :D

এইখানে আরেকটি প্রশ্ন আসে, আমিতো নিজের ক্লাসের মেথড দিয়ে ডেটা পরিবর্তন করছি তাহলে `Encapsulation` এর দরকার কোথায়? `Encapsulation` দরকার কারণ `Public Data` পুরাই `Public` আর আমি অন্য কোন `Class` এর `Object` দ্বারা `Access` পেতে পারি।

```cpp
#include <iostream>
using namespace std;
 
class Person
{
public:
    string name;
    int age;
};
 
class dataChanger
{
public:
    dataChanger(Person &p)
    {
        p.name = "I Changed it";
        p.age = 10;
    }
};
 
 
int main()
{
    Person person;
    person.name = "The Name has been set";
    person.age = 99;
    cout << person.name << endl;
    cout << person.age << endl;
    dataChanger danger(person);
    cout << person.name << endl;
    cout << person.age << endl;
}
```

### আউটপুট:
```
The Name has been set
99
I Changed it
10
```

বিগিনারদের জন্য প্রোগ্রামটি একটু জটিল হতে পারে, এখানে দুইটি ক্লাস ব্যবহার করা হয়েছে, একটি হল `Person` এবং আরেকটি হল `dataChanger`। `dataChanger` এর মেথড একটাই এবং সেটা তার কনস্ট্রাক্টর*। `dataChanger` এ আমরা একটি `Person Class` এর `Object` এর রেফারেন্স পাঠাই এবং তার `Attribute` গুলো পরিবর্তন করে দেয়। তাহলে দেখা যাচ্ছে `public` অ্যাট্রিবিউটগুলো আসলেই `Public` এবং তা অন্যান্য ক্লাসের `Method` দ্বারা `Accessible!`

আমরা যদি শুধু এই পরিবর্তনটা করি তাহলে অন্য ক্লাসের মেথড আর Access পাবে না:
```cpp
class Person
{
private:
    string name;
    int age;
};
```

যেসব মেথড ও অ্যাট্রিবিউট `Encapsulated` করতে চান সেগুলোকে `Access Modifier` দ্বারা `Modify` করতে হবে। `C++` এ কোন এক্সেস `Modifier` না ব্যবহার করলে ডিফল্ট `Modifier` হিসেবে `private` কাজ করবে। আপাতত `Encapsulation` নিয়ে এতটুকুই। এরপরে আমরা `Constructor` নিয়ে আলোচনা করব।

## Constructor:

কোন ক্লাসের `Constructor` একটি ফাংশন ছাড়া কিছুই নয়। কিন্তু এর একটি বিশেষত্ব আছে। `Constructor` এর প্রধান বিশেষত্ব হল একে `Call` করা লাগে না। `Object` তৈরি হওয়ার সাথে সাথে এই ফাংশনে যতগুলো স্টেটমেন্ট থাকবে সেগুলো অন্যান্য সাধারণ ফাংশনের মত `Execute` করতে থাকে এবং এটি একাধিক আর্গুমেন্ট নিতে পারে কিংবা নাও নিতে পারে, আরেকটি বৈশিষ্ট্য হল এটি কিছু `Return` করে না। তাহলে একনজরে `Constructor` এর বৈশিষ্ট্যগুলো হল:

*    একে `Call` করা লাগে না, অবজেক্ট তৈরি হওয়ার সাথে সাথেই রান হয়
*    এক বা একাধিক `Argument` থাকতে পারে কিংবা আর্গুমেন্ট নাও থাকতে পারে
*    কোন কিছু `Return` করে না
*    `Constructor` যেহেতু ফাংশন তাই এই ফাংশনের নাম অবশ্যই সংশ্লিষ্ট ক্লাসের নাম হতে হবে

##### একটি উদাহরণ দেখা যাক:
```cpp	
#include <iostream>
using namespace std;
 
class Person
{
public:
    string name;
    int age;
    Person(string string_as_argument, int int_as_argument)
    {
        name = string_as_argument;
        age = int_as_argument;
    }
};
 
int main()
{
    Person A("Mr. A", 5);
    cout << "My name is: " << A.name << endl;
    cout << "My age: " << A.age << endl;
}
```

##### আউটপুট:

```	
My name is: Mr. A
My age: 5
```

প্রোগ্রামটিতে কনস্ট্রাক্টর কোনটি? আগেই বলেছি, কনস্ট্রাক্টর হল সেই ফাংশন যার নাম আর ক্লাসের নাম একই এবং যেহেতু এটি কিছু রিটার্ন করে না তাই তার আগে কোনপ্রকার `Return Type` এর কিওয়ার্ড থাকবে না। এখানে আমাদের ক্লাস হল `Person` এবং `Person` নামের একটি ফাংশন দেখা যাচ্ছে যার প্রথম আর্গুমেন্ট `string` টাইপ এবং দ্বিতীয় আর্গুমেন্ট `int` টাইপ। এখন চোখ বন্ধ করে বলে দেওয়া যায় কনস্ট্রাক্টর আসলে কোনটি!

`Person` কনস্ট্রাক্টরটি কি করছে আসলে? এটি দুইটি আর্গুমেন্ট নিয়ে অবজেক্ট এর ভ্যারিয়েবলে তার মান বসাচ্ছে। অর্থাৎ আমরা যদি main ফাংশনের দিকে লক্ষ্য করি তাহলে দেখা যাবে আমরা Object তৈরি করার সময় দুইটা আর্গুমেন্ট পাস করেছি। একটি `“Mr. A”` এবং আরেকটি `5`। `Constructor` আর্গুমেন্ট দুটো নিয়ে ক্লাসের `name ও age` ভ্যারিয়েবলে বসিয়ে দিল। আদৌ বসালো কিনা তা দেখার জন্য আমরা `A.name` ও `A.age` দিয়ে অ্যাট্রিবিউটগুল‌ো চেক করলাম এবং আউটপুটে দেখলাম সেটা ঠিকঠাক আউটপুট দেখাচ্ছে।

আশা করি কিছুটা হলেও বুঝা গেল, `Constructor` যেহেতু ফাংশন তাই আমরা এটাকে নিচের মত করে বাইরে `Declare` করতে পারি!

```cpp
class Person
{
public:
    string name;
    int age;
    Person(string, int);
};
 
Person::Person(string n, int a)
{
    name = n;
    age = a;
}
```

কনস্ট্রাক্টরের কিভাবে ব্যবহার করে তা নিয়ে দেখা গেল! **এটি কতটা গুরুত্বপূর্ণ?**

### Constructor এর প্রয়োজনীয়তা:

কনস্ট্রাক্টরের মাধ্যমে আমরা অবজেক্ট এর `Initial` ভ্যালু বসিয়ে দিতে পারি, অন্য অর্থে আমরা যদি চাই যে একটি অবজেক্ট যখন তৈরি হবে তখন সেটা কিছু `Initial Value` নিয়ে তৈরি হোক। যাতে করে আমার সেই ক্লাসের ভ্যারিয়েবল ধরে ধরে ভ্যালুগুলো না বসানো লাগে। এবং সেই ভ্যালুগুলো ইনিশিয়ালি প্রসেসও করা যায় কনস্ট্রাক্টরের সাহায্যে।

আমরা দেখব `Arduino` তে `LiquidCrystal` লাইব্রেরি যখন আমরা ব্যবহার করব তখন কনস্ট্রাক্টরে কতগুলো পিন নাম্বার বসিয়ে দেব। ঔ পিন নাম্বারগুলো অবশ্যই একটি নির্দিষ্ট `Order` এ দিতে হবে। সাধারণ `Liquid Crystal Display` চালানোর জন্য সাধারণত ১৪-১৬ পিন ব্যবহার করা হয়। এখানকার কিছু নির্দিষ্ট পিন আমরা `Arduino` এর সাথে কানেক্ট করি এবং ঔ কানেক্ট করা পিনগুলো `Order` অনুসারে কনস্ট্রাক্টরে বসাই। বাকি সব কাজ হল `LiquidCrystal` লাইব্রেরির! অর্থাৎ ঔ পিন অনুযায়ী `LCD` তে `ReadWrite mode` সেট করা, ক্যারেক্টার শো করা ইত্যাদি সব সেটিংস কনস্ট্রাক্টরের মাধ্যমেই ঠিক হয়ে যায়। আমাদের নতুন কোন ফাংশন কল করা লাগে না কিংবা সেটা নিয়ে ঘাঁটাঘাঁটি করা লাগে না।

## Inheritance:

ইনহেরিট্যান্স বলতে যা বুঝায় কাজে আসলেই তাই। আমরা প্রত্যেকেই আমাদের নিজ নিজ পিতামাতার কিছু বৈশিষ্ট্যধারণ করে থাকি। একই বংশের লোকজনদের মধ্যে সাধারণত কিছু `Common` বৈশিষ্ট্য থাকা অস্বাভাবিক কিছু নয়। দোষগুণ যা আছে তা বংশানুক্রমে চলতে থাকে। OOP এর আরেকটি চমৎকার ফিচার `Inheritance!` পুরনো কোড ব্যবহার করা এবং আপনার নতুন ক্লাসকে আরও কিছু `Method ও Attribute` যোগ করে আরও শক্তিশালী করে তোলা `Inheritance` এর অন্যতম কাজ।

আমরা `Animal` ক্লাসে লক্ষ্য করি। `Animal` ক্লাসের সদস্যরা কি করে? খায়দায়, ঘুমায়, শিকার করে, চলাফেরা করে আরও অনেক কিছু করে। তাহলে আমরা সুবিধার্থে অল্প কিছু ফাংশন ও অ্যাট্রিবিউট দিয়ে `Animal Class` টি ডিফাইন করি:

```cpp
class Animal
{
public:
    void eat() { cout << "eating" << endl;}
    void sleep() {cout << "sleeping" << endl;}
    void hunt() {cout << "hunting" << endl;}
};
```

এখন যদি আমাকে বলা হয়, `Animal` ক্লাস বানাইলা ঠিকাছে, এবার `Bird` নামের আরেকটি ক্লাস তৈরি কর।

`Bird` যেহেতু `Animal` এর মধ্যেই পড়ে এবং তার `eat, sleep ও hunt` এই মেথডগুলোও রয়েছে তাই আমি আগের ক্লাসের মেথডগুলো কপি করে পেস্ট করে দিতে পারি আর যেহেতু এসব কাজের পাশাপাশি `Bird` এর আরেকটি `Method` আছে আর সেটা হল `Fly` বা উড়া। :)

#### তাহলে ক্লাসটি দাঁড়াবে:
```cpp
class Bird
{
public:
    void eat() {cout << "eating" << endl;}
    void sleep() {cout << "sleeping" << endl;}
    void hunt() {cout << "hunting" << endl;}
    void fly() {cout << "flying" << endl;}
};
```

কাজটা কি সুবিধাজনক হল? মোটেই না, যদি শখানেক মেথড ও অ্যাট্রিবিউট থাকে তাহলে কপি করতে করতেই অবস্থা খারাপ হয়ে যাবে! :P

তাহলে উপায় কী? `Inheritance Apply` করা :)

আমরা যদি এখন বলি `Bird inherits Animal` তাহলে `Animal class এর eat, sleep ও hunt` মেথডগুলো অটোমেটিক` চলে আসবে এবং তার জন্য আমার আর কিছুই করতে হবে না। যেটা অতিরিক্ত লাগবে সেটা শুধু অ্যাড করে দেব।

Inheritance Apply করার পরে কোডটি হবে:
```cpp	
#include <iostream>
using namespace std;
 
class Animal
{
public:
    void eat() { cout << "Eating" << endl;}
    void sleep() {cout << "Sleeping" << endl;}
    void hunt() {cout << "Hunting" << endl;}
};
 
class Bird : public Animal
{
public:
    void fly() { cout << "Flying" << endl; }
 
    // Calling the functions
    void activities()
    {
        eat();
        sleep();
        hunt();
        fly();
    }
};
 
int main()
{
    Bird b;          // Creating an object
    b.eat();
    b.sleep();          // Calling the functions individually
    b.hunt();
    b.fly();
    cout << "----------" << endl;
    b.activities();                    // Calling the 'activities' function which calls other functions
}
```

#### আউটপুট:
```	
Eating
Sleeping
Hunting
Flying
----------
Eating
Sleeping
Hunting
Flying
```

`Bird` এর ক্লাস থেকে আমরা দেখতে পাচ্ছি সেখানে `eat(), sleep(), hunt()` এর কোনটারই `Definition` দেওয়া নেই কিন্তু তারপরও ফাংশনগুলো আমরা `Call` করতে পেরেছি। এই ফাংশনগুলো এসেছে `Animal` ক্লাসের থেকে। `Animal` ক্লাসে ফাংশনগুলোর পুরোপুরিভাবে ব্যাখ্যা করা হয়েছে তাই `Inherit` করার সময় আমাদেরকে ফাংশনগুলো নিয়ে মাথা ঘামাতে হয় নি, ডিরেক্টলি কল করেই কাজ করা গেছে।

## ইনহেরিট্যান্স তাহলে প্রয়োগ করে কিভাবে?
```
class derivedClass : public baseClass { /* Put your attributes and methods here!*/ };
// derivedClass is the inherited one
// class[keyword] your_class_Name :[colon] public/private/protected[access modifier] base_Class
```

ইনহেরিট্যান্স ও বেশ বড় একটি টপিক, তাই অনেক কিছুই আলোচনা করা হল না। যতটুকু এখানে আলোচনা করা হল সেটুকুও এই কোর্সে লাগবে না আশাকরি।

## Polymorphism:

`Poly` মানে বহু সেটা আমরা আগেই জানি। `Polymorphism` কে সেই হিসেবে বহুরূপতাও বলা যেতে পারে। একই জিনিসের বিভিন্ন রূপ থাকা মানেই সেই জিনিসটি বহুরূপী। `OOP` তেও বহুরূপী আছে :P

পলিমর্ফিজমও বিশাল একটি টপিক। আগেই বলে রাখা ভাল, `Function Overloading, operator overloading` কে সরাসরি `Polymorphism` বলা যাবে না। পলিমর্ফিজমের সংজ্ঞায় `Function/Method overloading` পড়ে না কিন্তু একে পলিমর্ফিজমের একটি অংশমাত্র হিসেবে বলতে ক্ষতি নেই। সবকিছু সিম্পল রাখার জন্য আমি এখানে `Function Overloading` টা দেখাব এবং আপাতত একেই `Polymorphism` হিসেবে বলব। তারপরও আবারও দ্রষ্টব্য, `Function overloading` মানেই কিন্তু Polymorphism নয়।

### আলোচনা শুরুর আগে নিচের প্রোগ্রামটি দেখা যাক:
```cpp
#include<iostream>
 
using namespace std;
 
class Shape
{
public:
    float calcArea(int height, int width); // Calculate area for Rectangular shape
    float calcArea(double base, double height); // Calculate area for Triangular Shape
    float calcArea(int side);            // Calculate area for Square shape
};
 
float Shape::calcArea(int height, int width)
{
    return height * width;
}
 
float Shape::calcArea(double base, double height)
{
    return 0.5 * base * height;
}
 
float Shape::calcArea(int side)
{
    return side * side;
}
 
int main()
{
    Shape rectangle, triangle, square;
    cout << "Area of rectangle is: " << rectangle.calcArea(5,3) << endl;
    cout << "Area of triangle is: " << rectangle.calcArea(2.0,5.0) << endl;
    cout << "Area of square is: "   << square.calcArea(5) << endl;
}
```

#### আউটপুট:
```	
Area of rectangle is: 15
Area of triangle is: 5
Area of square is: 25
```

দেখা যাচ্ছে ক্লাস `Shape` এ আমরা তিনটা মেথড তৈরি করেছি একই নামের `calcArea` যার কাজ হল ক্ষেত্রফল বের করা। ভাল করে লক্ষ্য করলে দেখা যাবে তিনটি ফাংশনের নাম এক হতে পারে কিন্তু প্রত্যেকটার সাথে প্রত্যেকটার পার্থক্য বিদ্যমান। পার্থক্যগুলো হল, প্রথম ফাংশনটির আর্গুমেন্ট ২ টা এবং ২টাই `int` টাইপের। পরের ফাংশনটিরও আর্গুমেন্ট ২টা কিন্তু ২টার টাইপ হল `double` এবং শেষের ফাংশনটির আর্গুমেন্ট কেবল ১টি।

নাম এক হলেও আর্গুমেন্টের ভিত্তিতে ফাংশনগুলো আলাদা। কিন্তু কম্পাইলার কিভাবে বুঝবে আমি আসলে কোন ফাংশনটা `Call` করছি? `C++` কম্পাইলার এতটাই স্মার্ট যে সে শুধু আপনার দেওয়া আর্গুমেন্ট টাইপ বা কয়টা আর্গুমেন্ট দিয়েছেন সেটা দেখেই বুঝতে পারবে আসলে আপনি কোন ফাংশনটি `Call` করছেন। এই পদ্ধতির কেতাবি নাম `Function / Method overloading`। আমরা আপাতত একেই পলিমর্ফিজম হিসেবে চিহ্নিত করছি।

আর এখানেই অবজেক্ট ওরিয়েন্টেড প্রোগ্রামিংয়ে ইতি টানলাম। OOP এর অনেক ফিচার বাদ পড়েছে ও জিনিসগুলো সাধারণ রাখার জন্য অনেক ভুলভাল কথা লিখেছি। আর্ডুইনো প্রোগ্রামিংয়ে OOP এর ব্যবহার যদিও আমরা কদাচিৎ দেখব তারপরও এই বিষয়গুলোতে ধারণা রাখা জরুরি। পরের পরিচ্ছদে আমরা সিরিয়াল কম্যুনিকেশন সম্পর্কে মোটামুটি জানার চেষ্টা করব। সেখানে অবজেক্ট ওরিয়েন্টেড প্রোগ্রামিংয়ের সব ব্যাপার না থাকলেও সাধারণ ধারণা থাকলে বুঝতে অসুবিধা হবে না। তাছাড়া পরবর্তীতে `Header` ফাইল তৈরি করা ও এর ব্যবহারও দেখানো হবে, তখন OOP জানলে কোড অনেকাংশে সংক্ষিপ্ত ও `Readable` ও `Organized` করা সম্ভব।
