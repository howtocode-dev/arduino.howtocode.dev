
# অবজেক্ট ওরিয়েন্টেড প্রোগ্রামিং পরিচিতি (প্রথম ভাগ)

## যা যা দরকার:


*  `Codeblocks/Codelite/Eclipse` বা সমমানের IDE বা C++ কম্পাইলার, `Text Editor – Syntax Highlighter` সহ

আজকে `Arduino` নিয়ে তেমন কথা হবে না। শুধু `OOP` বা `Object Oriented Programming` নিয়েই আলোচনা করা হবে। `OOP` মূলত আলোচনা করা হবে `C++` ল্যাঙ্গুয়েজে। `C++` জানেন না, কোন সমস্যা নেই, যেকোন একটা ল্যাঙ্গুয়েজে `OOP` আয়ত্ব করলেই হয়, তবে ল্যাঙ্গুয়েজভেদে এর ইম্প্লিমেন্টেশন আলাদা হয়। অবশ্যই `OOP` একটি বিশাল জিনিস কিন্তু এখানে মোটমাট ২ ভাগে `OOP` আলোচনা করা হবে কারণ ইচ্ছা করলেই কম কথায় `OOP` এর বেসিক জিনিসগুলো তুলে ধরা যাবে কিন্তু সেটা পরবর্তীতে সমস্যা তৈরি করতে পারে তাই সবদিক বিবেচনা করে `OOP` এর পোস্টটা যতটা পারা যায় Informative ও Implementation বেজড রাখার চেষ্টা করা হবে।

## প্রোগ্রামিং মডেল [Programming Paradigm]:

আমরা যখনই কোন প্রোগ্রাম লিখি তখন নিচের মডেলগুলোর মধ্যে যেকোন একটি মডেলকে অনুসরণ করে প্রোগ্রাম লিখে থাকি। অনেক মডেলই আছে এবং কিছু কিছু প্রোগ্রামিং ল্যাঙ্গুয়েজ নির্দিষ্ট কিছু মডেল মেনে চলে। `Java` কে একটি পিওর `OOP` ল্যাঙ্গুয়েজ বলা চলে। কারণ `Java` কোড চালাতে গেলে আপনাকে কমপক্ষে একটি ক্লাস ও একটি মেইন ফাংশন ব্যবহার করতেই হবে। আবার `C++` এ আমরা `Procedural/Functional/OOP` ইত্যাদি যেকোন মডেল অ্যাপ্লাই করতে পারি। আমি এখানে দুইটি মডেলের কথা বলছি।

## Procedural:

একে `Imperative Programming` বলা হয়ে থাকে। `C` তে আমরা যেসব কোড লিখি তা প্রায় সবই `Procedural`। কারণ
কোডটি শুরু থেকে শেষ পর্যন্ত চলে এবং লাইন বাই লাইন (পড়ুন স্টেটমেন্ট বাই স্টেটমেন্ট) এক্সিকিউট হয়। অন্য কথায় Top To `Bottom Approach`। যখন একটা নির্দিষ্ট কাজ আমাদের করতে হয় এবং তার জন্য এমন একটি প্রোগ্রাম লিখলেই হয় যেটা টপ টু বটম রান করবে এবং সমস্যাটি সমাধান করবে তখন আমরা Procedural প্রোগ্রামিং মডেল ব্যবহার করে থাকি। এই মডেলে একাধিক ফাংশন ও একটি মেইন ফাংশন ব্যবহার করা হয়। `BASIC, Pascal ও C তে Procedural Programming` মডেল অনুসরণ করা হয়। সফটওয়্যার ডেভেলপিংয়ে এর প্রয়োগ নেই বললেই চলে। C তে একটি Procedural Programming এর উদাহরণ:

```cpp
	
int add(int a, int b);

int main(){
    int firstNum = 6;
    int secondNum = 15;
    int sum;
    sum = add(firstNum,secondNum);
    printf("sum= ",sum);
    return 0;
}

int add(int a,int b){
    int result;
    result = a + b;
    return result;
}
```

## Object Oriented:

একই প্রোগ্রাম যদি আমরা `C++` এ অবজেক্ট ওরিয়েন্টেড স্টাইলে লিখি তাহলে হবে এইরকম:

```cpp
#include <iostream>

class addNumbers
{
public:
    int sum;
    addNumbers(int, int); // এটা হল Constructor, Constructor কিছু রিটার্ন করে না, চিন্তা করার কিছু নেই পরে আলোচনা করা হবে
};

addNumbers::addNumbers(int num1, int num2)
{
    sum = num1 + num2;
}

int main()
{
    addNumbers object(1,2);
    std::cout << "Sum: " << object.sum;
}
```

`Object Oriented Programming` এর অ্যাপ্রোচ বটম টু টপ। অবজেক্ট ওরিয়েন্টেড ডিজাইনে যেটা থাকতেই হবে তা হল ক্লাস ও অবজেক্ট। এটা ছাড়া `OOP` চিন্তাই করা যায় না। বেশ কয়েকটি কারণে সফটওয়্যার ডেভেলপিং থেকে হার্ডওয়্যার প্রোগ্রামিংয়ে এর জনপ্রিয়তা চরম পর্যায়ের। `OOP` এর এই কারণ বা ফিচারগুলো হল:

*    `Class, Object`
*    `Encapsulation`
*    `Inheritance`
*    `Polymorphism`
*    এগুলোর পাশাপাশি যেটা আলোচনা করা হবে: `Constructor, Destructor`

## Class, Object:

আমাদের আশেপাশে যা আছে তাই `Object` এবং কতগুলো `Object` এর বৈশিষ্ট্য অনুযায়ী তাদেরকে একটা নির্দিষ্ট দলে ফেলা যায়। এই কনসেপ্টের উপর ভিত্তি করে `Object` গুলোকে একটি নির্দিষ্ট `Class` দ্বারা ডিফাইন করা হয়ে থাকে। আমরা গৃহপালিত পশুদেরকে একটি ক্লাস এর আওতায় আনি, নাম দিলাম `Pet`। `C++` এ `Pet` কে ক্লাস হিসেবে ডিফাইন করতে হলে আমাদের লিখতে হবে `class* Pet`। আচ্ছা, এবার `Pet` দের আমরা কি কি করি? তাদের নাম দিই, খাবার খেতে দিই এবং তাদের ধরণ অনুযায়ী আমাদের তারা Feedback দেয়। এই Feedback, `Pet` এর `Object` ভেদে বিভিন্ন ধরণের হতে পারে। কিন্তু ভালভাবে লক্ষ্য করলে দেখা যাবে তাদের কিছু সাধারণ বা `Common` বৈশিষ্ট্য `('Properties')` আছে। যেমন তারা খাবার খায়, ডাক দেয়, নাম ধরে ডাকলে সাড়া দেয়, এবং ভাল ট্রেনিং পেলে অনেক কিছু করে দেখাতে পারে। তাহলে `Pet` ক্লাসের `Object` গুলোর `Name, age` ইত্যাদি হল তার `Attributes`, আর খাবার খাওয়া, ডাক দেওয়া ইত্যাদি কাজগুলো তার `Method` বা প্রোগ্রামিংয়ে আমরা `Function` আকারে লিখে থাকি। Method গুলোকে আবার `Member Function` হিসেবেও ডাকা হয়।

```cpp	
class Pet
{
public:
    string name;
    void eat();
    void utter();
};
```

আপাতত `public:`** নিয়ে চিন্তা করার দরকার নাই। পরের লাইনগুলো দেখা যাক।

আমি `name` ভ্যারিয়েবলকে `string` টাইপ হিসেবে ডিফাইন করলাম, তার `Method` গুলোকে ফাংশন হিসেবে ডিফাইন করলাম। যেটা মনে রাখতে হবে সেটা হল `class Pet { // blablabla };` <- এই সেমিকোলনটার কথা।

আমি এখানে মেথডগুলোর একটা লিস্ট দেখিয়েছি। কিন্তু `Method` গুলো কীভাবে কাজ করবে সেটা লিখিনি। `Method` গুলো কীভাবে কাজ করবে সেটা দুইভাবে দেখানো যায়।

*    ক্লাসের ভিতরে [Inside of Class]
*    ক্লাসের বাইরে [Outside of Class]

উপরের প্রোগ্রামটি যদি আমি ক্লাসের ভিতরে লিখে দেখাই তাহলে এমন হবে:

```cpp
class Pet
{
public:
    string name;
    void eat()
    {
        cout << "Gulp gulp gulp..... ... .." << endl;
    }
    void utter()
    {
        cout << "meaw .... meaw ..." << endl;
    }
};
```

ঠিক যেমন আমরা ফাংশন ডিফাইন করি ঔভাবেই। এবার ক্লাসের বাইরে লিখলে দেখাবে:
```cpp
class Pet
{
public:
    string name;
    void eat();
    void utter();
};
 
void Pet::eat()
{
    cout << "Gulp ... gulp... gulp.." << endl;
}
 
void Pet::utter()
{
    cout << "Meaw..... meaw.... " << endl;
}
```

প্রথমে আমরা একটা লিস্ট দিলাম কি কি থাকবে, তারপর Method গুলো কীভাবে কাজ করবে সেটা লিখলাম। তাহলে, `C++` এ ক্লাসের বাইরে `Method` ডিফাইন করার নিয়ম হল:
```	
//[returnType] [ClassName] :: [methodName(argument)]
//Here-> '::' is called Scope Resolution Operator
 
void Pet :: eat()
{
    // Code goes Here
}
```

`‘::’` কে স্কোপ রেজোল্যুশন অপারেটর বলা হয়। নামটা অনেক ভারী হলেও কাজটা সহজ। খালি বলে দেওয়া কোন ফাংশন কোন ক্লাসে থাকে :)
### এই পর্যন্ত যা শিখলাম:

*    ক্লাস তৈরি করা
*    ক্লাসের জন্য `Attribute` ও `Method` তৈরি করা
*    `Method` কে ক্লাসের ভিতরে ও বাইরে কীভাবে ডিফাইন করা যায়

### এখন যা যা শিখব:

*    `Object` তৈরি করা
*    `Object` এর `Variable` বা `Attribute এ Value` বসানো
*    `Object` এর `Method Call` করা
*    `object` কে `Argument` হিসেবে `Pass` করা
*    `Class, object` ব্যবহার করে একটি পূর্ণাঙ্গ প্রোগ্রাম তৈরি করা

এই পর্যন্ত যেসব কিছু শেখা হয়ে গেল তা কি আসলেই শিখেছেন? না শিখলে কষ্ট করে আরেকটিবার পড়ুন, বুঝতে সমস্যা হলে Comment করুন। সামনে আরেকটু জটিল হতে পারে।

### Object তৈরি:
```cpp	
class Pet {}; // Assume it is the class
 
int main()
{
    Pet dog; // Object Created!
}
// className objectName /* To create an object */
```

#### Object এর ভ্যারিয়েবলে মান বসানো:
```cpp	
#include <iostream>
using namespace std;
class Pet
{
public:
    string name;
};
 
int main()
{
    Pet dog, cat;
    dog.name = "Tommy";
    cat.name = "Tom";
    cout << "Name of the cat is: " << cat.name << endl;
    cout << "Name of the dog is: " << dog.name << endl;
}
```

প্রোগ্রামে দেখা যাচ্ছে আমরা `Pet` ক্লাস দিয়ে দুইটি অবজেক্ট তৈরি করেছি। ধরলাম, একটা হল `Dog` আরেকটা হল `Cat`।পোষাপ্রাণীর নাম রাখা বাঞ্ছনীয় তাই `dog` এর নাম দিলাম `Tommy` এবং `cat` এর নাম দিলাম `Tom`। এখানে আরেকটি ব্যাপার লক্ষ্যণীয়, আমরা নাম দেওয়ার সময় `dot operator` বা `objectName.variable = “Value”`। Scope Resolution Operator` এর কাজ হল কোন `Member Function` কোন `Class` এর অন্তর্ভুক্ত। আর `Dot operator` এর কাজ হল `Object` এর নির্দিষ্ট কোন `Member Function` বা `Variable এ Access` দেওয়া। `name` একটি `string` টাইপ ভ্যারিয়েবল `Pet` ক্লাসের জন্য। কিন্তু মজার বিষয় হল `Pet` ক্লাসে আমি দুইটি `Object` তৈরি করে তাদের ভিন্ন ভিন্ন নাম দিয়েছি যদিও তারা একই ক্লাসের অন্তর্ভুক্ত।

ধরি, `variable = cat.name`, তাহলে `cat.name = “Tom”` হবে, `variable = “Tom”` , মানে `“Tom”` স্ট্রিংকে আমরা স্ট্রিংটাইপ ভ্যারিয়েবলে বসালাম (অবশ্যই cat অবজেক্টের variable এ)।

##### উপরের প্রোগ্রামের আউটপুট:

```	
Name of the cat is: Tom
Name of the dog is: Tommy
```

#### নিচের ছবিটি `Pet` ক্লাসের UML*** (Unified Modeling Language) Diagram:

![alt text](http://i.imgur.com/ZIce9mE.png)

আর এই ছবিটি হল অবজেক্ট তৈরি করার পরে:

![alt text](http://i.imgur.com/PSVFzaV.png)

### Object এর Method Call করা:

আগের মতই, `object.functionName(argument)` এভাবে অবজেক্টের `Method` কে `Call` করা যায়।

```cpp	
#include <iostream>
using namespace std;
class Pet
{
public:
    string name;
    void sayName()
    {
        cout << "My name is " << name << endl;
    }
};
 
int main()
{
    Pet cat;
    cat.name = "Thomas";
    cat.sayName();
}
```

প্রোগ্রামে প্রথমে `cat Object` এর নাম অ্যাসাইন করলাম। এবং অ্যাসাইন করার পর `sayName()` ফাংশনটি `Call` করলাম।

আউটপুট:
```	
My name is Thomas
```

#### কোন একটি ফাংশনে Object কে Argument হিসেবে পাস করা:

```cpp
	
#include <iostream>
using namespace std;
class Pet
{
public:
    string name;
};
 
void sayName(Pet petObject, string petName) // This is NOT A MEMBER FUNCTION, it is just a function in the program!
{
    petObject.name = petName; // Name has been assigned by taking the name from the argument
    cout << "Name of the pet is: " << petObject.name << endl;
}
 
int main()
{
    Pet cat;
    sayName(cat, "Thomas"); //  This will print "Name of the pet is: Thomas"
    cout << cat.name << endl; // This will print nothing!!!
}
```

আমরা জানি, ফাংশনে আর্গুমেন্ট পাস করা যায় দুইভাবে, `Pass by reference` এবং `Pass by value` হিসেবে। উপরেরটা হল `Pass by Value`। প্রোগ্রামে `void sayName` ফাংশনটি কোন ক্লাসের অন্তর্ভুক্ত নয়, এটি একটি অবজেক্ট ও একটি স্ট্রিংকে আর্গুমেন্ট হিসেবে নিয়ে, অবজেক্টের `Attribute name` এ শুধু `string` টা বসিয়ে দিয়েছে, এবং পরের স্টেটমেন্টে প্রিন্ট করে দেখিয়েছে।

##### আউটপুট:
```
Name of the pet is: Thomas
```

আমরা যদি মূল প্রোগ্রাম `[int main() অংশ]` লক্ষ্য করি তাহলে দেখতে পাব, `sayName` এ আমরা `cat` অবজেক্ট পাস করে ফাংশনের মাধ্যমে `cat` এর নাম আউটপুটে দেখতে পাচ্ছি। যদি আমি `cat.name` কে `cout` করি তাহলে কিছুই দেখা যাচ্ছে না। কারণ কি? কারণ হল `Pass by value`।

ধরুন, আমি আপনাকে একটি ওয়েবপেইজের লিঙ্ক দিলাম `(URL)`। এখন যদি ঔ লিঙ্কে কোন পরিবর্তন হয়, তাহলে পরিবর্তন যেমন আপনিও দেখতে পারবেন আমিও পারব। যদি আপনি আপনার পিসি থেকে লিঙ্কটি ডিলেট করে দেন তাহলে ওয়েবপেজের কিছুই হবে না। এটাই হল `Pass by reference`।

যদি আমি আপনাকে ঔ `URL` এর একটি পেজ প্রিন্ট করে দেই তাহলে সেটি হবে `Pass by value`, যদি ঔ `URL` এর ওয়েবপেজে কোন পরিবর্তন আসে তাহলে নিশ্চয়ই আপনি আপনার প্রিন্টকৃত পেজটিতে দেখতে পাবেন না। এবং যদি ওটা আপনি নষ্ট করে দেন তাহলে আপনি নিজের কপিটি ধ্বংস করলেন। অর্জিনাল কপি ঠিকি তাদের ওয়েবসাইটে থাকবে।

উপরের প্রোগ্রামটি `Pass by value` হওয়ার কারণে মূল কপির কোন পরিবর্তন হয় নি।

একই প্রোগ্রাম আমি যদি `Pass by reference` দিয়ে লিখি তাহলে:
```cpp	
......
void sayName(Pet &petObject, string petName) // I just put an & before the object!
{
    petObject.name = petName;
    cout << "Name of the pet is: " << petObject.name << endl;
}
 
int main()
{
    Pet cat;
    sayName(cat, "Thomas"); //  This will print "Name of the pet is: Thomas"
    cout << cat.name << endl; // This will print "Thomas"
}

```

##### এটার আউটপুট:
```	
Name of the pet is: Thomas
Thomas
```

`Pass by reference` এ আমি `cat` এর লোকেশন পাঠাই `&` চিহ্নটির মাধ্যমে। আমি `cat` অবজেক্টটি তৈরি করে তার লোকেশন ফাংশনে পাঠালাম এবং ফাংশনটি নতুন অবজেক্ট তৈরি না করে (আসলে নতুন অবজেক্ট তৈরি করলেও লোকেশন একই নির্দেশ করছে) `cat` অবজেক্টের লোকেশনের `name` টা পরিবর্তন করে দিল। `Pass by Value` তে যে অবজেক্টটি তৈরি করে অর্থাৎ, `petObject != cat [Not equal]` কিন্তু `Pass by reference` এ `petObject == cat` কারণ দুটি অবজেক্ট মূলত একটাই লোকেশন নির্দেশ করে আর সেটা হল `cat` এর লোকেশন। তাই `petObject` এর `name` পরিবর্তিত হওয়া মানে কিছুই না `cat` এর `name` পরিবর্তিত হওয়া যেহেতু তাদের লোকেশন একই!


### কেস স্টাডি: [Led Blinking in Console using OOP!]

নিচের কোডটি রান করলে `Led blinking` দেখতে পাবেন কনসোলে, মানে কিছু বোরিং টেক্সট আপনাকে দেখাবে কত নাম্বার পিনে led জ্বলছে, কত টাইম নিয়ে ব্লিংকিং করছে এই আরকি।

```cpp	
#include <iostream>
#include <Windows.h>
using namespace std;
 
class Led
{
public:
   int ledPin;
   Led(int pinNumber);
   void pinMode(int);
   void blinkLed(int delay);
};
 
Led::Led(int pinNumber)
{
    ledPin = pinNumber;
    pinMode(pinNumber);
}
 
void Led::pinMode(int pin)
{
    cout << pin << " is set as output" << endl;
}
 
void Led::blinkLed(int delay)
{
    cout << "Led at " << ledPin << " is on" << endl;
    Sleep(delay);
    cout << "Led at " << ledPin << " is off" << endl;
    Sleep(delay);
}
 
int main()
{
    int usDelay, pinNumber, turn;
    cout << "Enter Delay, Pin number and Turns [sequentially, example: 1000 13 2]: ";
    cin >> usDelay, cin >> pinNumber, cin >> turn;
    Led led(pinNumber);
    while (turn > 0){
    led.blinkLed(usDelay);
    turn--;
    }
}
```
#### আউটপুট:
```
Enter Delay, Pin number and Turns [sequentially, example: 1000 13 2]: 1000 13 2
13 is set as output
Led at 13 is on
Led at 13 is off
Led at 13 is on
Led at 13 is off
```

#### নোট:

##### Access Modifiers:

`C++` এ তিন ধরণের `Access Modifiers` আছে, `public, private ও protected`। এটা `Encapsulation` বা `Data Hiding` এর অন্তর্গত। তাই এখানে আলোচনা না করে পরবর্তী মূল পোস্টে আলোচনা করা হবে।

### UML Diagram:

এখানে `UML Diagram` বলতে আমরা `Class` কে চিত্র দ্বারা প্রকাশ বুঝাব `[Class Diagram]`। এটি বিশাল জিনিস এবং এই সিরিজের আলোচ্য বিষয়বস্তু না। নিচে একটি ক্লাস ডায়াগ্রাম [(উইকিপিডিয়া থেকে সংগৃহীত)](http://en.wikipedia.org/wiki/Class_diagram):

![alt text](http://i.imgur.com/aZDZbMO.png)

*    সবার উপরের অংশ হল `Class Name`। এটা বোল্ড হয় ও মাঝখানে থাকে, প্রথম বর্ণটি `Capitalized` থাকে
*    মাঝের অংশে `Attributes` বা `Variable` থাকে। `Left aligned` ও প্রথম বর্ণ `Lowercase`
*    শেষের অংশে `Method` থাকে। `Left aligned` ও প্রথম বর্ণ
*    `Attributes ও Method` এর আগে নিচের টেবিলের চিহ্ন থাকতে পারে `[Access Modifier -> +, -, #; Package -> ~, Derived-> / ]`

আজকে এই পর্যন্তই, পরবর্তী পরিচ্ছদে OOP এর বাকি বেসিক টপিকগুলো নিয়ে আলোচনা করা হবে।
