## আর্ডুইনো IDE ডাউনলোড, ইন্সটল ও বোর্ড কনফিগারেশন ও কিছু সাধারণ সমস্যার সমাধান


#### এই পোস্টের জন্য আপনার যা দরকার হবে [যদি আর্ডুইনো বোর্ড সংগ্রহ করতে ব্যর্থ হন তাহলে সিম্যুলেশন বেজড পোস্টের জন্য পরবর্তী পোস্ট থেকে শুরু করুন]

* প্রায় 100MB ডেটাসহ ইন্টারনেট কানেকশন [যদি ডাউনলোড না করতে চান সেক্ষেত্রে আপনাকে IDE যোগাড় করে নিতে হবে]
* Arduino UNO R3 অথবা Arduino Mega 2560 [এখানে আমি Arduino Mega 2560 ব্যবহার করব, ভয়ের কিছু নেই দুইটার কনফিগার করার পদ্ধতি একই রকম]
* USB A – B Cable [আপনার ক্রয়কৃত আর্ডুইনোর সঙ্গে যে কেবলটি দেওয়া আছে সেটা]

> দ্রষ্টব্য: টিউটোরিয়ালটি উইন্ডোজ অপারেটিং সিস্টেম ইউজারদের জন্য। লিনাক্সে কোন ঝামেলা করা লাগে না, লিনাক্সের জন্য এখান থেকে ([32 bit](http://arduino.cc/download.php?f=/arduino-1.0.6-linux32.tgz), [64 bit](http://arduino.cc/download.php?f=/arduino-1.0.6-linux64.tgz)) IDE ডাউনলোড করুন আর আর্ডুইনো পিসির সাথে কানেক্ট করুন। সমস্যা এড়ানোর জন্য টার্মিনাল থেকে gksudo arduino কমান্ড দ্বারা আর্ডুইনো চালু করুন।

### Arduino IDE ডাউনলোড ও ইন্সটলেশন:

আর্ডুইনোর জন্য কোড লেখা, আপলোড করা ও সিরিয়াল মনিটরিংয়ের জন্য আপনার অফিশিয়াল IDE ডাউনলোড করতে হবে। ওপেনসোর্স হওয়ার কারণে IDE টা জমকালো না তবে কাজ চলে আরকি। যদি IDE এর ইন্টারফেস আপনার পছন্দ না হয় সেক্ষেত্রে Sublime Text Editor কে কীভাবে আর্ডুইনো IDE হিসেবে ব্যবহার করা যায় সেটা দেখানো হবে। তহালে কাজ শুরু করা যাক। ছবিতে ক্লিক করে ডাউনলোড করুন:

[![Download Arduino IDE](http://i.imgur.com/ufPtdcb.png)](http://arduino.cc/download.php?f=/arduino-1.0.6-windows.exe)


*    ডাউনলোডেড ফাইলটা Run As Administrator হিসেবে চালু করুন:

![alt text](http://i.imgur.com/1Mf9ogM.png)
*    I Agree:

![alt text](http://i.imgur.com/TarVsYS.png)
*    Next:

![alt text](http://i.imgur.com/xOz0g7W.png)
*    Install:

![alt text](http://i.imgur.com/aPotbSA.png)
*    অপেক্ষা করুন:

![alt text](http://i.imgur.com/tTG8xDq.png)
*    Install এ ক্লিকান:

![alt text](http://i.imgur.com/YDofWHP.png)
*    Close চাপুন:

![alt text](http://i.imgur.com/0RYvtl5.png)

#### Arduino Board ড্রাইভার সেটাপ:
*   আপনার আর্ডুইনো বোর্ডটি পিসির সাথে কানেক্ট করে উইন্ডোজের Device Manager ওপেন করুন:

![alt text](http://i.imgur.com/dO87raa.png)

*   এবার Ports এ ক্লিক করলে যদি Arduino দেখায় তাহলে বুঝবেন ড্রাইভার অটো ইন্সটল হয়ে গেছে:

![alt text](http://i.imgur.com/Fm3Dqj8.png)


*    আর যদি তা না দেখা যায় তাহলে Other devices এ যতগুলো Unknown Device আছে সেগুলোতে নিচের পদ্ধতিতে আর্ডুইনো ড্রাইভার সেটাপ দেওয়া শুরু করবেন। একটা না একটাতে সেটাপ হবেই :P
*    Unknown Device এ রাইট ক্লিক করে Update Driver Software দিন:

![alt text](http://i.imgur.com/860dFoi.png)


*    Browse my computer for driver software এ ক্লিক করুন:

![alt text](http://i.imgur.com/0lsBYij.png)

*	Browse এ ক্লিকান:

![alt text](http://i.imgur.com/uDrwqDm.png)

*    Arduino Folder টি খুঁজে বের করে Driver ফোল্ডারটি সিলেক্ট করে OK দিন:

![alt text](http://i.imgur.com/1RtT6Iu.png)

*    Next:

![alt text](http://i.imgur.com/55B9YBi.png)

*	এবার ওকে ওকে নেক্সট যা আসবে সবগুলোই দিন, যদি বলে যে This driver software is incompatible for the device বা এই জাতীয় কথা তাহলে অন্য Unknown Device এ একই পদ্ধতিতে Driver আপডেট করার ট্রাই করুন।

### Arduino Configure করা ও প্রথমবারের মত Program বার্ন করা:

*	বোর্ডের ড্রাইভার ঠিকঠাক সেটাপ হয়ে গেছে? তাহলে দেরি না করে প্রোগ্রাম আপলোড করে ফেলুন ঝটপট। **প্রোগ্রাম আপ্লোড করার আগে আর্ডুইনো বোর্ড ও COM Port সিলেক্ট করে নিতে হবে।**

*	Arduino IDE ওপেন করুন, নিচের স্প্ল্যাশ দেখাবে:

![alt text](http://i.imgur.com/6XbuZgH.png)

*	এবার Tools > Serial Port > COMX [Device Manager এর Port থেকে দেখে নিতে পারেন আপনার আর্ডুইনো কোন Port এ আছে]

![alt text](http://i.imgur.com/x7eQ1jE.png)

*	আবার Tools > Board > Arduino …. [এখানে আপনার বোর্ডটি সিলেক্ট করবেন, আপনার বোর্ড UNO হলে সবার প্রথমটা আর Mega হলে ছবিতে যেটা দেখানো হয়েছে সেটা সিলেক্ট করলেই হবে]

![alt text](http://i.imgur.com/cDOMWMF.png)

*	এখনো তো আর্ডুইনো কোডিং শেখা হয় নি? সমস্যা নাই, IDE তেই শখানেক Example দেওয়া আছে, তার যেকোনটা আপ্লোড দিলেই চলে। কিন্তু আপনার Arduino যে কোড অনুযায়ী কাজ করছে সেটা দেখার জন্য Blink নামের Example টি বেশ কার্যকর। Arduino UNO, Mega তে 13 নাম্বার পিনের সাথে একটি LED যুক্ত থাকে। তাই আমরা External Led ছাড়াও Led Blinking এর কোড কাজ করছে কিনা সেটা দেখতে পারি।

*	Example এর জন্য File > Examples > Basics > Blink এ ক্লিক করুন, নতুন উইন্ডো ওপেন হবে:

![alt text](http://i.imgur.com/IlUUUja.png)


*	Arduino তে আগে থেকেই Blink প্রোগ্রামটি বার্ন করা থাকে, তাই আমার পরামর্শ হল Blink প্রোগ্রামটি বার্ন করার আগে delay এর মধ্যে 1000 এর বদলে আপনি অন্য কোন সংখ্যা বসান, যেমন delay(100) বা delay(50) যাতে আমরা নতুন প্রোগ্রাম আর পুরনোটার মধ্যে তফাত খুঁজে পাই।

*	[নোট: delay(int) ফাংশনটির আর্গুমেন্ট ইন্টিজার টাইপ এবং এখানে যেটা দেওয়া হবে তার একক মিলিসেকেন্ড, অর্থাৎ 1000 এর মানে হল 1 second]

*	এরপর Upload বাটনটিতে ক্লিক করুন:

![alt text](http://i.imgur.com/JNKRrdP.png)

*	এবার যদি ব্লিংকিং দেখতে পান বা ব্লিংকিংয়ে ভিন্নতা নজরে আসে অথবা যদি Arduino IDE তে দেখেন কোন ঝামেলা ছাড়াই Upload Completed আসে তাহলে বুঝতে হবে কোড আপলোড হয়েছে!

#### Arduino IDE কাস্টোমাইজেশন:

*	আর্ডুইনোর সবই ভাল খালি IDE টাই পছন্দ হয় না। ফন্টের অবস্থা ভাল না, মাউজ স্ক্রল করে জুম করা যায় না আরও অনেক সমস্যা। যাই হোক, কাস্টোমাইজেশন বলতে এখানে ফন্ট কিভাবে পরিবর্তন করবেন সেটাই দেখানো হয়েছে, Heavy Customization এর জন্য গুগলিং করাই ভাল হবে।

*	ফন্ট চেঞ্জ করার জন্য অনেক কাজ করতে হবে, File > Preferences:

![alt text](http://i.imgur.com/Fm6UQbH.png)

*	তীর চিহ্নিত লেখাটায় ক্লিক করুন:

![alt text](http://i.imgur.com/ezr9qGl.png)

*	নতুন ফোল্ডার আসবে একটি টেক্সট ফাইল দেখতে পাবেন preferences.txt নামে, সেটা ওপেন করুন, editor.font খুঁজে বের করে Monospaced এর জায়গায় আপনার পছন্দের ফন্টের নাম লিখুন [আমি এখানে উইন্ডোজের সবচেয়ে ভাল Monospaced font হিসেবে Consolas ব্যবহার করেছি], plain কে পরিবর্তন না করে পাশে যে সংখ্যা আছে সেটা পরিবর্তন করুন। সংখ্যাটি ফন্টের সাইজ নির্দেশ করে।

**সবকিছু এডিট করার পর অবশ্যই Ctrl+S বা Save করবেন!**

![alt text](http://i.imgur.com/UZFHcDl.png)

*	 এবার IDE Restart করলেই দেখবেন ফন্টের আকার ও ফন্ট পরিবর্তিত হয়েছে।

![alt text](http://i.imgur.com/yApBpBo.png)

### কিছু সাধারণ সমস্যা ও তার সমাধান [F.A.Q / Troubleshooting]

###### সমস্যা: আমার আর্ডুইনো UNO এর ড্রাইভার কোনভাবেই সেটাপ দেওয়া যাচ্ছে না। সবগুলো পদ্ধতি ট্রাই করলাম, কাজ করছে না। আমি উইন্ডোজ ৮ / ৮.১ / ৭ ব্যবহার করছি।

#####	সমাধান:

**উইন্ডোজ ৮/৮.১ এর জন্য:**

Shift কি চেপে আপনার পিসি রিস্টার্ট দিন। দেখবেন রিস্টার্ট নিয়ে একটা ব্লু স্ক্রিন এসেছে। Choose an option আসবে, Troubleshoot > Advanced options >  Startup settings > Restart। এবার পিসি রিস্টার্ট হলে আবার ব্লু স্ক্রিন আসবে ও কিছু লেখা আসবে, কিবোর্ড থেকে 7 চাপুন। এখন পিসি অন হলে আবারও একই নিয়মে ড্রাইভার সেটাপ দেওয়ার চেষ্টা করুন। এবারও না হলে উইন্ডোজ ৭ এর সমাধান ট্রাই করুন।

**উইন্ডোজ ৭ এর জন্য:**

আর্ডুইনো বোর্ডটি কানেক্টেড রাখুন এরপর কাজগুলো করুন।

Device Manager > Unknown Device [আপনার আর্ডুইনো বোর্ডটি] > Update driver software > Browse My computer for driver software > Let me pick from a list of device drivers from my computer > Modems >  বামপাশ থেকে Compaq ও ডানপাশের Models থেকে Richochet Wireless USB Model সিলেক্ট করুন [লিস্ট আপডেট হতে একটু টাইম দিন] > Yes > Installing দেখাবে। ইন্সটলড হলে Baud Rate 9600 করে দিন ও একটি COM পোর্ট সিলেক্ট করুন। COM পোর্ট সিলেক্ট করার সময় 50-60 এর মধ্যে সিলেক্ট করার চেষ্টা করবেন। এখন আর্ডুইনো আইডিই থেকে ঔ কম পোর্ট সিলেক্ট করে কোড আপলোড করুন।

###### সমস্যা: কোড আপ্লোড দিতে গেলে এই এরর দেখাচ্ছে : avrdude: stk500_getsync(): not in sync: resp=0x00

##### সমাধান:

আপনার আর্ডুইনো বোর্ডটির COM পোর্ট পরিবর্তন করতে হবে। Device Manager > Ports > Arduino [Right Click] > Properties > Port setting  > Advanced > Com Port Number > ইচ্ছামত সিলেক্ট করুন (অবশ্যই যেগুলো unused)। এবার পরিবর্তিত পোর্ট সিলেক্ট করে কোড আপলোড দেওয়ার চেষ্টা করুন।

###### সমস্যা: আমার সমস্যাটি এই লিস্টে নেই

##### সমাধান:

মন্তব্যে সমস্যাটি উল্লেখ করুন অথবা মেইল পাঠান manashmndl[অ্যাট]gmail[ডট কম]
পরবর্তী পোস্টে আমরা আর্ডুইনো বোর্ডের ব্যাপারে বেশকিছু টার্ম ও কম্পোনেন্ট সম্পর্কে জানব ও আর্ডুইনো প্রোগ্রামিংয়ের সাথে পরিচিত হব।
