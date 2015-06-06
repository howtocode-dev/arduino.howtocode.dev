# আর্ডুইনো বেসিক [পর্ব: ১০]:: আর্ডুইনো লাইব্রেরি তৈরি ও ইনহেরিট্যান্স প্রয়োগের মাধ্যমে লাইব্রেরি মডিফাই করা

## এই পর্বের জন্য যা যা প্রয়োজন:

১। একটি ভাল `C/C++ IDE [Code::blocks, Codelite, Qt Creator, Visual Studio..]` অথবা `Text Editor [Notepad++, Sublime Text Editor, Atom, Brackets ...]`

২। লাইব্রেরি টেস্ট করার জন্য `Official Arduino IDE` 
৩। যেকোন আর্ডুইনো বোর্ড
৪। বোর্ড না থাকলে সিম্যুলেশনের জন্য প্রোটিয়াস (Proteus)
৫। LCD Module (যেকোন ডাইমেনশনের)

## লাইব্রেরি তৈরি করার যৌক্তিকতা:

আর্ডুইনোতে যে এত সহজে কোড করতে পারছেন, শুধু `digitalWrite(size_t, MODE)` কিংবা `analogRead(size_t)` ফাংশনগুলো ব্যবহার করলেই `LED` ইচ্ছামত জ্বলানেভা করা অথবা সেন্সর থেকে রিডিং নেওয়া্। `Serial.read()` ব্যবহার করে সহজেই সিরিয়াল কম্যুনিকেশন এস্টাব্লিশ করে ডিবাগিং করা ইত্যাদি কাজগুলো সহজ হয়েছে মূলত `Arduino` লাইব্রেরির কারণে। `Arduino` আসলে একটি `Avr` চিপ ছাড়া কিছুই না। এতে Communication এর জন্য `Atmega8U2 / Atmega16U2` চিপ ব্যবহার করা হয়েছে এবং ব্যাটারি জনিত সমস্যা এড়ানোর জন্য বিল্ট-ইন ভোল্টেজ রেগুলেটর* বসানো হয়েছে। এ সব কিছু বাদ দিলে শুধু `Atmega328p-PU` চিপটাই থেকে যায়। আর আমরা সবাই জেনে গেছি এটা মূলত একটি `AVR` চিপ। `AVR-C` তে করা প্রোগ্রামগুলোকে সহজ করার জন্য `Arduino Library` ব্যবহার করা হয়েছে্। কারণ সবাই বিটওয়াইজ অপারেশনকে শুরুর দিকে বেশ ঝামেলার কাজ বলে মনে করে, আর তাই তাদের হার্ডওয়্যারের প্রতি আগ্রহ উবে যায়। তাই এটাকে সহজ ও আনন্দদায়ক করার জন্য হাজারখানেক লাইনের কোড লিখে আর্ডুইনো অফিশিয়াল লাইব্রেরি তৈরি করা হয়। 

প্রোগ্রামগুলো এত সহজ হওয়ার কারণ মূলত ঔ লাইব্রেরি। ওপেন-সোর্সের মজা মূলত এখানেই, নিজের ইচ্ছামত সবকিছু ভেঙ্গে গুঁড়িয়ে আবার নতুন করে শুরু করা যায়। Code Reusability এর ক্ষেত্রে লাইব্রেরির জুড়ি নেই। 

যেমন, PIC এর জন্য MikroC এর তৈরি লাইব্রেরি আপনি ইচ্ছা করলেই ব্যবহার করতে পারবেন না। এই লাইব্রেরি ব্যবহার করার জন্য আপনাকে Pay করতে হবে। সেখানে আর্ডুইনো লাইব্রেরি ব্যবহার করা/ মডিফাই করা কিংবা মডিফাই করে রিডিস্ট্রিবিউট করার ক্ষেত্রে কোন বাঁধা নেই।

## লাইব্রেরি তৈরি ও ব্যবহার 

লাইব্রেরি তৈরি করতে ও এর সঠিক ব্যবহার করতে দক্ষতার প্রয়োজন হয়। লাইব্রেরি শুধু লিখলেই হয় না, সহজবোধ্য ভ্যারিয়েবল তৈরি, সুন্দর সিনট্যাক্স ও কমেন্টিংয়ের মাধ্যমে বোঝা যায় কোন লাইব্রেরি কতটা ভাল। 

ধরা যাক, আপনি মেমরি এফিশিয়েন্ট একটি লাইব্রেরি তৈরি করলেন, কিন্তু আপনার ডকুমেন্টেশনটা যুতসই হল না, সেক্ষেত্রে যিনি আপনার লাইব্রেরি ব্যবহার করবে সে অনেক সমস্যার সম্মুখীন হতে পারে। কিন্তু আরেকজনের লাইব্রেরি তেমন মেমরি এফিশিয়েন্ট হলনা কিন্তু তার লাইব্রেরির ডকুমেন্টেশন, সিনট্যাক্স ও কমেন্টিংয়ের কারণে তার লাইব্রেরি ব্যবহার করা খুবই আরামদায়ক হলে সেই লাইব্রেরিটাই সবার কাছে গ্রহণযোগ্য হবে। তাই লাইব্রেরি তৈরি করার সময় আপনাকে এসব কিছু খেয়াল রাখতে হবে। 

লাইব্রেরি ব্যবহার করার জন্য লাইব্রেরি লেখকের ডকুমেন্টেশন ভালভাবে বুঝার চেষ্টা করতে হবে। তিনি কোন কোন মেথড তৈরি করেছেন, কোনটা দিয়ে কি করে; কোনটার কী লিমিটেশন অথবা আপনার যদি মনে হয় আপনি সেটাকে মডিফাই করে আরও ভাল কিছু তৈরি করতে পারবেন, সেক্ষেত্রে আপনি সে লাইব্রেরি আপডেট দিয়ে তাকে জানিয়ে দিতে পারেন। 

## আর্ডুইনোর কিছু ডিফল্ট ও গুরুত্বপূর্ণ লাইব্রেরির লিস্ট

আমরা আর্ডুইনোর এই কোর্সে যেসব লাইব্রেরি ব্যবহার করব

* [SoftwareSerial]()
* [LiquidCrystal]()
* [Wifi]()
* [NewPing]()
* [SPI]()

ইত্যাদি

## আর্ডুইনো লাইব্রেরির গঠন 

ধরি আমার আর্ডুইনো লাইব্রেরির নাম `MyLibrary`

তাহলে,

* `MyLibrary` ফোল্ডার: এই ফোল্ডারে আপনার লাইব্রেরির প্রয়োজনীয় ফাইলগুলো থাকবে
    * `examples` ফোল্ডার `[MyLibrary/examples/MyExample/MyExample.ino]`: এই ফোল্ডারে আপনার তৈরিকৃত লাইব্রেরি ব্যবহার করে কোন একটি প্রোগ্রাম থাকবে, সেটা অবশ্যই `.ino` এক্সটেনশনবিশিষ্ট আর্ডুইনো ফাইল হতে হবে। এবং সেই ফাইলটি আরেকটি ফোল্ডারে রাখতে হবে যার নাম একই।
    * `changelog.txt [MyLibrary/changelog.txt]` : লাইব্রেরির ভার্সন আপডেট, নতুন ফিচার অ্যাড ইত্যাদি তথ্য এই টেক্সট ফাইলে অ্যাড করতে হবে। (optional)
    * `keywords.txt [MyLibrary/keywords.txt]` : আপনার লাইব্রেরির Class, method, properties এ যদি Syntax Highlighting প্রয়োগ করতে চান, অথবা যদি চান আপনার তৈরিকৃত Class, method ইত্যাদি IDE রঙিন করে দিক তাহলে এই ফাইলে সেই Keyword গুলো লিখতে হবে। (optional)
    * `MyLibrary.h [MyLibrary/MyLibrary.h]` : এটা হল আপনার লাইব্রেরির হেডার ফাইল, হেডার ফাইলকে আমরা মেন্যুও বলতে পারি। আপনার তৈরি ক্লাসের যাবতীয় সব তথ্য এইখানে রাখলে একনজরে দেখতে সুবিধা হয়। লাইব্রেরি ও ক্লাসের নাম একই হতে হবে এমন কোন কথা নেই, কিন্তু এক রাখাটা সুবিধাজনক। স্ট্রাকচার্ড ও স্প্লিট ফাইল বেজড প্রোগ্রামিংয়ে Header ফাইল ব্যবহার করা ভাল প্রোগ্রামিং প্র্যাক্টিস।
    * `MyLibrary.cpp [MyLibrary/MyLibrary.cpp]` : এটা হল আপনার তৈরি করা Header ফাইলের সোর্স ফাইল। নাম একই হতে হবে এমন কোন কথা নাই, নাম এক হলে চিনতে সুবিধা হয়। 
    * অন্যান্য *.h ও *.cpp ফাইল [MyLibrary/Others.h, MyLibrary/Others.cpp]: আপনার তৈরি লাইব্রেরি যদি অন্য কোন লাইব্রেরি / ক্লাস বা মেথড নির্ভরশীল হয় তাহলে সে ফাইলগুলো আপনার লাইব্রেরির ফোল্ডারে রেখে দেবেন। 
    
### এই পর্বের লাইব্রেরির উদাহরণ:

আমরা `LiquidCrystal` লাইব্রেরিকে মডিফাই করব, তাহলে আমাদের লাইব্রেরির জন্য যে ফাইল/ ফোল্ডারগুলো লাগবে, একনজরে দেখা যাক:

* আমি যে নামে লাইব্রেরি তৈরি করতে চাই সে নামের একটা ফোল্ডার তৈরি করলাম (লাইব্রেরি তৈরি শেষে আর্ডুইনোতে ইম্পোর্ট করব)

![create_dir](http://i.imgur.com/X1R4Obb.jpg)

* ফোল্ডারে স্কেলিটন ফাইলগুলো তৈরি করে ফেললাম 
    * `MyLiquidCrystal.h`
    * `MyLiquidCrystal.cpp`
    * `keywords.txt`
    * `changelog.txt`
    * `examples\ScrollText\ScrollText.ino`

![important_files](http://i.imgur.com/x6IvdJn.png)

* `MyLiquidCrystal` লাইব্রেরিটা আর্ডুইনো অফিশিয়াল `LiquidCrystal` ও `Arduino.h` এর উপর নির্ভরশীল। তাই `LiquidCrystal` লাইব্রেরির সোর্স (`LiquidCrystal.h` ও `LiquidCrystal.cpp`) ডাউনলোড করে ও `Arduino.h` ডাউনলোড করে আমার লাইব্রেরির ডিরেক্টরিতে রাখলাম

![added_new_files](http://i.imgur.com/BpyCzzk.png)

# লাইব্রেরি লজিক


### যা করতে চাই:

LiquidCrystal লাইব্রেরিকে মডিফাই করে আমরা একটা মেথড অ্যাড করতে চাই, যার কাজ হবে একটা নির্দিষ্ট স্ট্রিং বা শব্দকে LCD তে স্ক্রল করানো। LiquidCrystal এ অলরেডি এই মেথড তৈরি করা আছে কিন্তু সেই মেথড পুরো ডিস্প্লে স্ক্রল করতে থাকে। এইখানে আমি একটি Buggy code লিখব যেটা পরবর্তীতে আপনাকে ঠিক করতে হবে। 


### অ্যালগরিদম

* যে স্ট্রিংকে স্ক্রল করাতে হবে সেটাকে (0,0) তে প্লেস করে প্রিন্ট করব
* স্ট্রিং থেকে LCD এর বাউন্ডারি দূরত্ব ক্যালকুলেট করব 

### কাজের ধারা:

যেভাবে কাজটি করব

## MyLiquidCrystal.h ফাইলে MyLiquidCrystal ক্লাস তৈরি করে LiquidCrystal ইনহেরিট করা

### ১। Header ফাইল লেখার নিয়ম

* হেডার ফাইল লেখার জন্য যে নাম দিয়ে হেডার ফাইলটি তৈরি করতে চান, `#ifndef` প্রিপ্রসেসর ব্যবহার করে সে নামটি সবার প্রথমে লিখতে হবে। যেমন এখানে: `#ifndef MyLiquidCrystal_h`
* তারপরে সেটাকে `#define` প্রিপ্রসেসর দিয়ে ডিফাইন করতে হবে। এখানে: `#define MyLiquidCrystal_h`
* সবার শেষে `#endif` ব্যবহার করতে হবে

একনজরে একটি হেডার ফাইল

```cpp
//Header File Name: MyLiquidCrystal.h
#ifndef MyLiquidCrystal_h
#define MyLiquidCrystal_h

//Logic Goes here

#endif
```

### ২। প্রয়োজনীয় ফাইল #include করা 

যেহেতু আমি `LiquidCrystal` লাইব্রেরিটি ও `Arduino.h` ব্যবহার করছি তাহলে সেটা `#include` করতে হবে।

সুতরাং,

```cpp
#ifndef MyLiquidCrystal_h
#define MyLiquidCrystal_h

//Naming unsigned 8 bit integer as "byte"
typedef uint8_t byte;

//Adding Necessary Header Files
#include "Arduino.h"
#include "LiquidCrystal.h"

#endif
```

### ৩। প্রয়োজনীয় ক্লাস, প্রোপার্টি ও মেথড তৈরি:

#### i) Inheritance প্রয়োগ

যেহেতু আমরা একটি ক্লাস তৈরি করে LiquidCrystal কে ইনহেরিট করব সেকারণে Header ফাইলের নাম দিয়ে একটি ক্লাস তৈরি করে কোলন `:` চিহ্ন দিয়ে আমরা LiquidCrystal ক্লাসটিকে ইনহেরিট করব যাতে `LiquidCrystal` এর সকল মেথড, প্রোপার্টি আমরা ব্যবহার করতে পারি।

```cpp
#ifndef MyLiquidCrystal_h
#define MyLiquidCrystal_h

//Naming unsigned 8 bit integer as "byte"
typedef uint8_t byte;

//Adding Necessary Header Files
#include "Arduino.h"
#include "LiquidCrystal.h"

//Added Class
class MyLiquidCrystal : public LiquidCrystal {
    //Methods And Properties go here
};

#endif
```
#### ii) প্রয়োজনীয় Properties অ্যাড করা

আমার এই লাইব্রেরির জন্য বেশকিছু প্রোপার্টি অ্যাড করব। প্রোপার্টি ও মেথড প্রোগ্রামারভেদে পরিবর্তিত হয়। অনেকে সাধারণ কাজের জন্য অনেক মেথড ও প্রোপার্টি ব্যবহার করতে পারে (যেমন আমি) আর এক্সপেরিয়েন্সড প্রোগ্রামারদের অনেক কম প্রোপার্টি ও মেথড হলেই চলে যায়। প্রোপার্টিগুলোকে সাধারণত `private` রাখা বেটার ও এই প্রোপার্টি ভ্যালু পরিবর্তন করার জন্য আমরা `public get set` মেথড ব্যবহার করতে পারি। 

ক্লাসের ভিতরের অংশ যদি বিবেচনায় আনি তাহলে,

```cpp

class MyLiquidCrystal : public LiquidCrystal {
    private:
    
    //Initial Position
    byte x = 0;
    byte y = 0;

    //Scroll Delay
    byte scrollDelay;

    //Storing LCD Row and Column
    byte lcdRows;
    byte lcdCols;

    //Getting the string length for out of bound calculation
    byte wordLength;

    //Distance from first character to the last boundary of lcd
    byte distance;
};

```

#### iii) প্রয়োজনীয় Method অ্যাড করা

আমার কাজের প্রয়োজনীয় প্রোপার্টি অ্যাড করে ফেললাম, এবার মেথড অ্যাড করা বাকি। মেথডের জন্য আমরা Access Modifier হিসেবে `public` ব্যবহার করব।

```cpp
class MyLiquidCrystal : public LiquidCrystal {
    public:
    
    //Function for scrolling
    void word_scroll(char *str, byte del);

    //Setting LCD Dimension
    void set_lcd(byte col, byte row);

    //Get LCD Dimension
    byte get_row(void);
    byte get_col(void);


    //Using Constructor from LiquidCrystal
    MyLiquidCrystal(byte rs, byte en, byte d4, byte d5, byte d6, byte d7) : LiquidCrystal (rs, en, d4, d5, d6, d7) {}

    //Getting the distance of word
    byte get_distance(void);
};

```
দ্রষ্টব্য: MyLiquidCrystal এ আমরা LiquidCrystal এর কনস্ট্রাক্টর ব্যবহার করতে চাই। আর সুপার ক্লাসের কনস্ট্রাক্টর ব্যবহার করার ফরম্যাট হল এটা `derived_class(int arg1, int arg2) : base_class(arg1, arg2) {}`। এইভাবে কনস্ট্রাক্টর তৈরি করলে বেজ ক্লাসের কনস্ট্রাক্টর কল হয়। এই কাজটা করার কারণ সবার শেষে বলা হবে।


### ৪। সোর্স ফাইল লেখা [MyLiquidCrystal.cpp]

হেডার ফাইল তৈরি করার পরে সোর্স ফাইলে সেই ফাংশনগুলোর লজিক বসাতে হয়। 

    
