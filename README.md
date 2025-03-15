# carimport-taxation
# Overview
## User case/stories.
-The system keeps an updated Used MV guidelines valuation of car units imported to Uganda.
-The user enters a car model (specific), year and cc of the car.
-The search starts and if a match is found, the car is returned with its coresponding HS code and the CIF value of the car.
-The code is then used to calculate the taxes based on the CIF value and HS code.
This project is meant to ease the work of taxation of car unit imported in Uganda. As a software developer, i needed some language that can persofm such a huge task so fast and easily, requires less computing powere to peroform and can be deployed on every machine.

The purpose is to provide a solution to the existing issues. Currently, the taxes are calculated upon declaration, which gives a client no time to plan and know the taxes. This software will give the tax estimate/actual values based of the value guideline to client so they can plan better.


[Software Demo Video](https://www.loom.com/share/48aa0228e7014a449ab87c999031bd2d?sid=73f591b4-d0e1-4f99-a822-cc4f196da386 ![image](https://github.com/user-attachments/assets/0ad427f7-15d3-4ff9-9700-767233be1e5e)
)

# Development Environment

Tools included Vs code, C++ compliler clang.

language used: C++

# Useful Websites

{Make a list of websites that you found helpful in this project}

- [Microsoft](http://url.link.goes.here](https://learn.microsoft.com/en-us/cpp/ide/walkthrough-deploying-your-program-cpp?view=msvc-170))
- [Visual studio code](https://code.visualstudio.com/docs/languages/cpp)

# Future Work

- Add more cars than the current list (expect to add more than 1000 units)
- Include Tonnage of cars that used that instead of cc.
- convert the total taxes in local curreny (ugx), this will need this software to sync so it can pick the current exchange rate from Bank of Uganda to use in conversion.
  
#Meanings:
- MV - Motor Vehicle.
- car model - The model of the car, including its name.
- CC - Cubic Centimeters (A unit of volume used to measure the engine's displacement or capacity.
- HS Code - Harmonized System code (used to identify goods and articles in global trade for purposes of trade tariffs and taxation.
- CIF value - Cost Insurance Freight( its an incoterm of trade, that shows what aspects the goods are under so a final value can be reached onto which taxes will be calculated. Cost is the cost of the car at market price, Insurance is the cost for insuring the car in transit, freight is the charge for moving the car from one location to another/country.
