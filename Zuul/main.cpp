//Zuul game made by Aneeq 1/5/2021 and Ehan Masud helped me with a bit of syntax stuff while Nihal helped me with the navigation part. 
#include <iostream>
#include <cstring>
#include <vector>
#include "room.h"
#include "item.h"
int main() {//THe main class
  //all the items and rooms initialized
  room* onetwenty = new room();
  room* mathclass = new room();
  room* bathroom = new room();
  room* office = new room();
  room* train = new room();
  room* cafeteria = new room();
  room* electricityroom = new room();
  room* nuclearreactor = new room();//Mr Galbraith and his Nerd Cronies developing a robot that shoots nuclear lasers
  room* chemistryroom = new room();
  room* healthroom = new room();
  room* kimjungoonnuclearstudyroom = new room();
  room* kimjungoonpersonalroom = new room();
  room* swimmingpool = new room();
  room* physicsroom = new room();
  room* slingshotplane = new room();
  item* laptop = new item();
  item* mask = new item();
  item* charger = new item();
  item* swag = new item();
  item* trainitem = new item();
  int zero = 0;//creating every room, used some of ehans help to get a start on this. The zero variable was ebcause i was confused why there was an lvalu eeerror earlier.
  strcpy(onetwenty-> description, "You are in 1-20 lab, coolest room ever");
  onetwenty-> haslaptop = false;
  onetwenty-> hasmask = false;
  onetwenty-> hascharger = false;
  onetwenty-> hasswag = false;
  onetwenty-> hastrain = false;
  onetwenty-> haswest = true;
  onetwenty-> hasnorth = true;
  onetwenty-> haseast = true;
  strcpy(mathclass-> description, "You are in the math class, where ms mcnamee is teaching math");
  mathclass-> haslaptop = false;
  mathclass-> hasmask = false;
  mathclass-> hascharger = false;
  mathclass-> hasswag = false;
  mathclass-> hastrain = false;
  mathclass-> hasnorth = true;
  mathclass-> haseast = true;
  mathclass-> hassouth = true;
  strcpy(bathroom-> description, "You are in the bathroom. It smells really bad, because Sunset decided to partner with Taco Bell");
  bathroom-> haslaptop = false;
  bathroom-> hasmask = false;
  bathroom-> hascharger = false;
  bathroom-> hasswag = false;
  bathroom-> hastrain = false;
  bathroom-> hasnorth = true;
  bathroom-> haseast = true;
  strcpy(office-> description, "You are in the office, and the window is broken because some object went flying through it.");
  office-> haslaptop = true;
  office-> hasmask = false;
  office-> hascharger = false;
  office-> hasswag = false;
  office-> hastrain = false;
  office-> hasnorth = true;
  strcpy(train-> description, "You are in the - What the hell? Theres a train room? The math and physics department developed a super speed train that apparently takes you to a secret room across the globe. East of this train takes you somewhere far far away...");
  train-> haslaptop = false;
  train-> hasmask = false;
  train-> hascharger = false;
  train-> hasswag = false;
  train-> hastrain = true;
  train-> hassouth = true;
  train-> haseast = true;
  strcpy(cafeteria-> description, "You are in the Cafeteria. Hey, theres taco bell!");
  cafeteria-> haslaptop = false;
  cafeteria-> hasmask = true;
  cafeteria-> hascharger = false;
  cafeteria-> hasswag = false;
  cafeteria-> hastrain = false;
  cafeteria-> haswest = true;
  cafeteria-> hasnorth = true;
  strcpy(electricityroom-> description, "You are in the electricity room, and currently the teachers are working on developing a high class charger that charges your computer in one second");
  electricityroom-> haslaptop = false;
  electricityroom-> hasmask = false;
  electricityroom-> hascharger = true;
  electricityroom-> hasswag = false;
  electricityroom-> hastrain = false;
  electricityroom ->haseast = true;
  electricityroom -> haswest = true;
  electricityroom -> hassouth = true;
  strcpy(nuclearreactor-> description, "You are in the nuclear reactor, Mr Galbraith is wearing a hazmat suit");
  nuclearreactor-> haslaptop = false;
  nuclearreactor-> hasmask = false;
  nuclearreactor-> hascharger = false;
  nuclearreactor-> hasswag = false;
  nuclearreactor-> hastrain = false;
  nuclearreactor -> haseast = true;
  nuclearreactor -> hassouth = true;
  strcpy(chemistryroom-> description, "You are in the chemistry room, 2 suspicious scientists are putting some vinegar like substance in baking soda.");
  chemistryroom-> haslaptop = false;
  chemistryroom-> hasmask = false;
  chemistryroom-> hascharger = false;
  chemistryroom-> hasswag = false;
  chemistryroom-> hastrain = false;
  chemistryroom -> hasnorth = true;
  chemistryroom -> haswest = true;
  chemistryroom -> hassouth = true;
  strcpy(healthroom-> description, "You are in the healthroom, and apparently someone got hit by a flying laptop and it caused them to get a sprained wrist. They are in the health room now");
  healthroom-> haslaptop = false;
  healthroom-> hasmask = true;
  healthroom-> hascharger = false;
  healthroom-> hasswag = false;
  healthroom-> hastrain = false;
  strcpy(kimjungoonnuclearstudyroom-> description, "You are in Kim Jung Un's Nuclear Study Room");
  kimjungoonnuclearstudyroom-> haslaptop = false;
  kimjungoonnuclearstudyroom-> hasmask = false;
  kimjungoonnuclearstudyroom-> hascharger = false;
  kimjungoonnuclearstudyroom-> hasswag = false;
  kimjungoonnuclearstudyroom-> hastrain = false;
  kimjungoonnuclearstudyroom-> haswest = true;
  kimjungoonnuclearstudyroom-> hasnorth = true;
  strcpy(kimjungoonpersonalroom-> description, "You are in Kim Jung Un's room. Why is Mr Galbraith here???....!");
  kimjungoonpersonalroom-> haslaptop = false;
  kimjungoonpersonalroom-> hasswag = true;
  kimjungoonpersonalroom-> hasmask = false;
  kimjungoonpersonalroom-> hascharger = false;
  kimjungoonpersonalroom-> hastrain = false;
  kimjungoonpersonalroom->hassouth = true;
  strcpy(swimmingpool-> description, "You are in the swimming pool room, where people are swimming like pros. ");
  swimmingpool-> haslaptop = false;
  swimmingpool-> hasmask = false;
  swimmingpool-> hascharger = false;
  swimmingpool-> hasswag = false;
  swimmingpool-> hastrain = false;
  swimmingpool-> hassouth = true;
  swimmingpool-> haseast = true;
  strcpy(physicsroom-> description, "You are in the physics room. The teacher is angry that students used calculus instead of memorizing formulas on the final exam. Probably don't want to make him more mad... ");
  physicsroom-> haslaptop = false;
  physicsroom-> hasmask = false;
  physicsroom-> hascharger = false;
  physicsroom-> hasswag = false;
  physicsroom-> hastrain = false;
  physicsroom-> haswest = true;
  physicsroom-> hassouth = true;
  physicsroom-> hasnorth = true;
  strcpy(slingshotplane-> description, "You went to the physics teacher's secret lair, and it smells horrible. There is a slingshot that sends you flying east. However, this slingshot is kinda scary...");
  slingshotplane-> haslaptop = false;
  slingshotplane-> hasmask = false;
  slingshotplane-> hascharger = false;
  slingshotplane-> hasswag = false;
  slingshotplane-> hastrain = false;
  slingshotplane-> haswest = true;
  slingshotplane-> hasnorth = true;
  slingshotplane-> haseast = true;
  slingshotplane-> hassouth = true;
  cout<<"Hey there! You are in 1-20 lab, the best class ever to exist in Sunset High School. Only thing is, the coolest person to ever exist in Sunset suggests that you to turn in your Classes project(If you dont, you will fail the class, and why would you want to fail the best class ever? If you do, you have some thinking to do), that you had 3 weeks to do, and you are lost. Now, this caused you to enrage, and you sent your computer flying somewhere, and you dont know where it is. you also chucked your charger lol... Find your charger and your computer! Meet Mr Galbraith in Kim Jung Un's personal room.";//entry msg
  cout<<endl;
  int a = 0;
  room* currentroom = onetwenty;//currentroom
  int bruhmomentcounter = 0;
  vector<char> inventory;
  while (a == 0) {//start of the game
    cout<<"The description of your room is:";
    currentroom -> printDescription();
    cout<< endl;
    currentroom -> printDirections();
    cout<<endl;
    currentroom -> printItems();
    cout<<endl;
    cout<<"Which direction you want to go? Say 'q' to quit, w to go west, s to  \
go south, n to go north, e to go east. say the item to pick it up and drop it";
    char d;
    cin>>d;
    if(d == 'q') {
      a = 1;
    }
    else if(d == 'w') {//if the direction happens what room are they in. nihal helped me on this becuase I did not relaly understand how I could use maps here.
      if(currentroom == onetwenty) {
	cout<<endl;
	currentroom = electricityroom;
      }
      else if(currentroom == electricityroom) {
	currentroom = nuclearreactor;
      }
      else if(currentroom = cafeteria) {
	currentroom = bathroom;
      }
      else if(currentroom = chemistryroom) {
	currentroom = mathclass;
      }
      else if(currentroom = physicsroom) {
	currentroom = swimmingpool;
      }
      else if(currentroom = kimjungoonnuclearstudyroom) {
	cout<<"you are in kim";
	cout<<endl;
	currentroom = train;
      }
      else if(currentroom = slingshotplane) {
	currentroom = onetwenty;
      }
    }
    else if(d == 'e') {
      if(currentroom == onetwenty) {
	currentroom = slingshotplane;
      }
      else if(currentroom == electricityroom) {
	currentroom = onetwenty;
      }
      else if(currentroom == nuclearreactor) {
	currentroom = electricityroom;
      }
      else if(currentroom == mathclass) {
	currentroom = chemistryroom;
      }
      else if(currentroom == bathroom) {
	currentroom = cafeteria;
      }
      else if(currentroom == swimmingpool) {
	currentroom = physicsroom;
      }
      else if(currentroom == train) {
	currentroom = kimjungoonnuclearstudyroom;
      }
      else if(currentroom == slingshotplane) {
	cout<<"HAHAHHAHAAHAHAHHAAHAHAHAHAHAHAHAHHAHAHA YOU HAVE DIED!!!!!!!!!!! THE SLINGSHOT SENT YOU FLYING AND YOU WENT SO FAST THAT YOU DIED!!!!";
	a = 1;
      }
      
    }
    else if(d == 's') {
      if(currentroom == onetwenty) {
	cout<<"There is no southern exit for onetwenty remember?";
      }
      else if(currentroom == swimmingpool) {
	currentroom = onetwenty;
      }
      else if(currentroom == electricityroom) {
	currentroom = chemistryroom;
      }
      else if(currentroom == nuclearreactor) {
	currentroom = mathclass;
      }
      else if(currentroom == mathclass) {
	currentroom = bathroom;
      }
      else if(currentroom == chemistryroom) {
	currentroom = cafeteria;
      }
      else if(currentroom == physicsroom) {
	currentroom = slingshotplane;
      }
      else if(currentroom == slingshotplane) {
	currentroom = office;
      }
      else if(currentroom == kimjungoonpersonalroom) {
	currentroom = kimjungoonnuclearstudyroom;
      }
      else if(currentroom == train) {
	currentroom = physicsroom;
      }
    }
    else if(d == 'n') {
      if(currentroom == onetwenty) {
        currentroom = swimmingpool;
      }
      else if(currentroom == chemistryroom) {
        currentroom = electricityroom;
      }
      else if(currentroom == mathclass) {
        currentroom = nuclearreactor;
      }
      else if(currentroom == bathroom) {
        currentroom = mathclass;
      }
      else if(currentroom == cafeteria) {
        currentroom = chemistryroom;
      }
      else if(currentroom == slingshotplane) {
        currentroom = physicsroom;
      }
      else if(currentroom == office) {
        currentroom = slingshotplane;
      }
      else if(currentroom == kimjungoonnuclearstudyroom) {
        currentroom = kimjungoonpersonalroom;
      }
      else if(currentroom == physicsroom) {
	currentroom = train;
      }
    }
    else if(d == 'p') {//pick up 
      cout<<"What do you want to pick up? Say first letter of object in lowercase, ie l for laptop";
      cout<<endl;
      char object;
      cin>>object;
      int count = 0;
      for (int i = 0; i < inventory.size(); i++) {
	if(inventory[i] == object) {
	  count++;
	}
      }
      item* objectitem;
      if(object == 'l') {
        if((count == zero) && (currentroom->haslaptop = true)) {
	  inventory.push_back(object);
	  currentroom->haslaptop = false;
	}
      }
      else if(object == 'c') {
	if((count == zero) && (currentroom->hascharger = true)) {
          inventory.push_back(object);
	  currentroom->hascharger = false;
        }
      }
      else if(object == 'm') {
	if((count == zero) && (currentroom->hasmask = true)) {
          inventory.push_back(object);
	  currentroom->hasmask = false;
        }
      }
      else if(object == 's') {
	if((count == zero) && (currentroom->hasswag = true)) {
          inventory.push_back(object);
	  currentroom->hasswag = false;
        }
      }
      else if(object == 't') {
	if((count == zero) && (currentroom->hastrain = true)) {
          inventory.push_back(object);
	  currentroom->hastrain = false;
        }
      }
    }
    else if(d == 'd') {//drop 
      cout<<"What do you want to drop? Say first letter of object in lowercase, ie l for laptop";
      cout<<endl;
      char object;
      cin>>object;
      int count = 0;
      int index = 0;
      vector<char> container;
      for (int i = 0; i < inventory.size(); i++) {
	container.push_back(inventory[i]);
        if(inventory[i] == object) {
          count++;
        }
      }
      item* objectitem;
      if(object == 'l') {
        if(count == 1) {
          inventory.clear();
	  for(int i = 0; i < container.size(); i++) {
	    if(container[i] != object) {//remove object from list
	      inventory.push_back(container[i]);
	    }
	  }
          currentroom->haslaptop = true;
        }
      }
      else if(object == 'c') {
        if(count == 1) {
	  inventory.clear();
	   for(int i = 0; i < container.size(); i++) {
            if(container[i] != object) {
              inventory.push_back(container[i]);
            }
          }
          currentroom->hascharger = true;
        }
      }
      else if(object == 'm') {
        if(count == 1) {
	  inventory.clear();
           for(int i = 0; i < container.size(); i++) {
            if(container[i] != object) {
              inventory.push_back(container[i]);
            }
          }
          currentroom->hasmask = true;
        }
      }
      else if(object == 's') {
        if(count == 1) {
          inventory.clear();
          for(int i = 0; i < container.size(); i++) {
            if(container[i] != object) {
              inventory.push_back(container[i]);
            }
          }
          currentroom->hasswag = true;
        }
      }
      else if(object == 't') {
        if(count == 1) {
          inventory.clear();
          for(int i = 0; i < container.size(); i++) {
            if(container[i] != object) {
              inventory.push_back(container[i]);
            }
          }
          currentroom->hastrain = true;
        }
      }
    }
    int laptopcount = 0;
    int chargercount = 0;//win checker
    for(int i = 0; i < inventory.size(); i++) {
      if(inventory[i] == 'l') {
	laptopcount++;
      }
      else if(inventory[i] == 'c') {
	chargercount++;
      }
    }
    if((laptopcount == 1) && (chargercount ==1)) {
      if(currentroom == kimjungoonpersonalroom) {
	cout<<"You won the game!";
	a = 1;
      }
    }
  }
  cout<<"Thanks for playing the game!";
  return 0;
}
