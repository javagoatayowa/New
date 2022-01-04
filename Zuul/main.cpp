#include <iostream>
#include <cstring>
#include <vector>
#include "room.h"
#include "item.h"
int main() {
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
  strcpy(onetwenty-> description, "You are in 1-20 lab, coolest room ever");
  onetwenty-> haslaptop = false;
  onetwenty-> hasmask = false;
  onetwenty-> hascharger = false;
  onetwenty-> hasswag = false;
  onetwenty-> hastrain = false;
  onetwenty-> haswest = true;
  strcpy(mathclass-> description, "You are in the math class, where ms mcnamee is teaching math");
  mathclass-> haslaptop = false;
  mathclass-> hasmask = false;
  mathclass-> hascharger = false;
  mathclass-> hasswag = false;
  mathclass-> hastrain = false;
  strcpy(bathroom-> description, "You are in the bathroom. It smells really bad, because Sunset decided to partner with Taco Bell");
  bathroom-> haslaptop = false;
  bathroom-> hasmask = false;
  bathroom-> hascharger = false;
  bathroom-> hasswag = false;
  bathroom-> hastrain = false;
  strcpy(office-> description, "You are in the office, and the window is broken because some object went flying through it.");
  office-> haslaptop = true;
  office-> hasmask = false;
  office-> hascharger = false;
  office-> hasswag = false;
  office-> hastrain = false;
  strcpy(train-> description, "You are in the - What the hell? Theres a train room? The math and physics department developed a super speed train that apparently takes you to a secret room across the globe ");
  train-> haslaptop = false;
  train-> hasmask = false;
  train-> hascharger = false;
  train-> hasswag = false;
  train-> hastrain = true;
  strcpy(cafeteria-> description, "You are in the Cafeteria. Hey, theres taco bell!");
  cafeteria-> haslaptop = false;
  cafeteria-> hasmask = false;
  cafeteria-> hascharger = false;
  cafeteria-> hasswag = false;
  cafeteria-> hastrain = false;
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
  strcpy(kimjungoonpersonalroom-> description, "You are in Kim Jung Un's room. You should probably leave soon....!");
  bathroom-> haslaptop = false;
  bathroom-> hasmask = false;
  bathroom-> hascharger = false;
  bathroom-> hasswag = true;
  bathroom-> hastrain = false;
  strcpy(swimmingpool-> description, "You are in the swimming pool room, where people are swimming like pros. ");
  swimmingpool-> haslaptop = false;
  swimmingpool-> hasmask = false;
  swimmingpool-> hascharger = false;
  swimmingpool-> hasswag = false;
  swimmingpool-> hastrain = false;
  strcpy(physicsroom-> description, "You are in the physics room. The teacher is angry that students used calculus instead of memorizing formulas on the final exam. Probably don't want to make him more mad... ");
  physicsroom-> haslaptop = false;
  physicsroom-> hasmask = false;
  physicsroom-> hascharger = false;
  physicsroom-> hasswag = false;
  physicsroom-> hastrain = false;
  strcpy(slingshotplane-> description, "You went to the physics teacher's secret lair, and it smells horrible. There is a slingshot that sends you flying north. However, this slingshot is kinda scary...");
  slingshotplane-> haslaptop = false;
  slingshotplane-> hasmask = false;
  slingshotplane-> hascharger = false;
  slingshotplane-> hasswag = false;
  slingshotplane-> hastrain = false;
  cout<<"Hey there! You are in 1-20 lab, the best class ever to exist in Sunset High School. Only thing is, the coolest person to ever exist in Sunset suggests that you to turn in your Classes project(If you dont, you will fail the class, and why would you want to fail the best class ever? If you do, you have some thinking to do), that you had 3 weeks to do, and you are lost. Now, this caused you to enrage, and you sent your computer flying somewhere, and you dont know where it is. you also chucked your charger lol... Find your charger and your computer!";
  cout<<endl;
  int a = 0;
  room* currentroom = onetwenty;
  while (a == 0) {
    cout<<"Which direction you want to go? Say 'q' to quit, w to go west, s to go south, n to go north, e to go east. say the item to pick it up and drop it";
    cout<<endl;
    cout<<"The description of your room is:";
    currentroom -> printDescription();
    cout<< endl;
    currentroom -> printDirections();
    cout<<endl;
    currentroom -> printItems();
    char d;
    cin>>d;
    if(d == 'q') {
    }
    else if(d == 'w') {
      if(currentroom == onetwenty) {
	currentroom = electricityroom;
      }
    }
    else if(d == 'e') {
    }
    else if(d == 's') {
    }
    else if(d == 'n') {
    }

  }
  cout<<"Thanks for playing the game!";
  return 0;
}
