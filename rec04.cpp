// Task 1
// Who are you? What is this program called?
// Zoe Dauphinee, recitation 4, pointers/this/dynamic objects/debugger


#include <iostream>   // needed for task 2
#include <vector>     // needed for task 27
using namespace std;  // needed for task 2


// Task 16 Complex definition
struct Complex {
   double real;
   double img;
};

// Task 17 PlainOldClass definition
class PlainOldClass {
public:
   PlainOldClass() : x(-72) {}
   int getX() const { return x; }
   void setX( int val )  { x = val; }
private:
   int x;
};

// Task 18 PlainOldClass2 definition
class PlainOldClassV2 {  
public:
   PlainOldClassV2() : x(-72) {}
   int getX() const { return x; }
   // void setX( int x )  { x = x; } // HMMMM???
   void setX( int x )  { this->x = x; } // No confusion!
private:
   int x;
};

// Task 28 Colour definition
class Colour {  
public:       
    Colour(const string& name, unsigned r, unsigned g, unsigned b)       
        : name(name), r(r), g(g), b(b) {}       
    void display() const { 
        cout << name << " (RBG: " << r << "," << g<< "," << b << ")"; 
    }   
private:       
    string name;      // what we call this colour       
    unsigned r, g, b; // red/green/blue values for displaying  
};  

// Task 29 SpeakerSystem definition
class SpeakerSystem {
   public:
   void vibrateSpeakerCones(unsigned signal) const {

      cout << "Playing: " << signal << "Hz sound..." << endl;
      cout << "Buzz, buzzy, buzzer, bzap!!!\n";
   }
};

// Task 29 Amplifier definition
class Amplifier {
public:
  void attachSpeakers(SpeakerSystem& spkrs)
   {
      if(attachedSpeakers) {
         cout << "already have speakers attached!\n";
      } else {
         attachedSpeakers = &spkrs;
      }
   }
  
   void detachSpeakers() { // should there be an "error" message if not attached?
      attachedSpeakers = nullptr; 
   } 
  
   void playMusic( ) const {
      if (attachedSpeakers) {
         attachedSpeakers -> vibrateSpeakerCones(440); 
      } else {
         cout << "No speakers attached\n";
      } 
   }
private:
   SpeakerSystem* attachedSpeakers = nullptr;
};

// Task 30 Person Definition
class Person {  
public:       
    Person(const string& name) : name(name) {}
    void movesInWith(Person& newRoomate) {
        if (this == &newRoomate) {
            cout << "Error: Cannot move in with oneself!" << endl;
            return;
        }
        else if (roomie != nullptr) {
            cout << "Error: Already have a roommate" << endl;
            return;
        }
        else if (newRoomate.roomie != nullptr) {
            cout << "Error: Already have a roommate" << endl;
            return;
        }
        roomie = &newRoomate;        // now I have a new roomie            
        newRoomate.roomie = this;    // and now they do too       
    }       
    const string& getName() const { return name; }
    // Don't need to use getName() below, just there for you to use in debugging.
    const string& getRoomiesName() const { return roomie->getName(); }  
private:
    Person* roomie;       
    string name;  
};           


int main() {
    cout << "Task 1\n";

    // Task 2
    cout << "Task 2\n";
    // Add code here
    int x;  
    x = 10;  
    cout << "x = " << x << endl;
        
    cout << endl;

    // Task 3 
    cout << "Task 3\n";
    // Using the debugger, set a breakpoint in main and run to
    // it. Observe the value of x.
    // [No new code]

    // Task 4
    cout << "Task 4\n";
    // Using the debugger, step forward observing the value of x
    // [No new code]

    // Task 5
    cout << "Task 5\n";
    // Watch window. Xcode equivalent? Gdb equivalent?
    // Activity: see x's value
    // [No new code]

    // Task 6
    cout << "Task 6\n";
    // Watch window to see the address of x
    // [No new code]

    // Task 7
    cout << "Task 7\n";
    // Watch window to see the value stored at the address of x
    // [No new code]
    
    // Task 8
    cout << "Task 8\n";
    // Add code. here
    int* p;
    p = &x;
    // p = 0x000000016fdff3ac;       (Task 9)
    cout << "p = " << p << endl;

    cout << endl;
    
    // Task 9
    cout << "Task 9\n";
    // Using the value you observe in &x, write a line of code to
    // directly assign that value to p. E.g. p = 0x0012fed4;
    // What happens? Should have a compiler error.
        // error: incompatible integer to pointer conversion assigning to 'int *' from 'long'
    
    // Task 10
    cout << "Task 10\n";
    // Run earlier print statement for "p = ". Observe the watch
    // window.
    // Then add code here:
    cout << "p points to where " << *p << " is stored\n";
    cout << "*p contains " << *p << endl;

    cout << endl;
    
    // Task 11
    cout << "Task 11\n";
    // Add code here
    *p = -2763;  
    cout << "p points to where " << *p << " is stored\n";  
    cout << "*p now contains " << *p << endl;  
    cout << "x now contains " << x << endl;

    cout << endl;
    
    // Task 12
    cout << "Task 12\n";
    // Add code
    int y(13);      
    cout << "y contains " << y << endl;      
    p = &y;      
    cout << "p now points to where " << *p << " is stored\n";      
    cout << "*p now contains " << *p << endl;      
    *p = 980;      
    cout << "p points to where " << *p << " is stored\n";      
    cout << "*p now contains " << *p << endl;      
    cout << "y now contains " << y << endl;

    cout << endl;
    
    // Task 13
    cout << "Task 13\n";
    // Add code here
    int* q;      
    q = p;      
    cout << "q points to where " << *q << " is stored\n";      
    cout << "*q contains " << *q << endl;

    cout << endl;
    
    // Task 14
    cout << "Task 14\n";
    // Add code here
    double d(33.44);      
    double* pD(&d);      
    *pD = *p;      
    *pD = 73.2343;      
    *p  = *pD;      
    *q  = *p;      
    // pD  = p;   // a value of type "int *" cannot be assigned to an entity of type "double *"
    // p   = pD;  // a value of type "double *" cannot be assigned to an entity of type "int *"
    
    // Task 15
    cout << "Task 15!!!\n"; // Yes, this is a VERY IMPORTANT task!
    // Const and pointers.
    // Add code here
    int joe = 24;  
    const int sal = 19;    
    int*  pI;  
    pI = &joe;  
    *pI = 234;
    //pI = &sal;                        // can't assign 'int*' to 'const int*'
    *pI = 7623;    

    const int* pcI;
    pcI = &joe;
    //*pcI = 234;                       // can't modify the value pcI points to since pcI is a const pointer
    pcI = &sal;
    //*pcI = 7623;                      // can't modify the value pcI points to since pcI is a const pointer

    //int* const cpI;                   // there has to be a default initialization for a pointer of type int* const
    int* const cpI(&joe);
    //int* const cpI(&sal);             // can't redefine what a pointer of type int* const points to
    //cpI = &joe;                       // seen as redefining a const pointer (even though that's what it already points to)
    *cpI = 234;  
    //cpI = &sal;                       // can't redefine what a pointer of type int* const points to
    *cpI = 7623;    

    //const int* const cpcI;            // there has to be a default initialization for a constant pointer
    const int* const cpcI(&joe);
    //const int* const cpcI(&sal);      // can't redefine what a pointer of type int* const points to
    //cpcI = &joe;                      // seen as redefining a const pointer (even though that's what it already points to)
    //*cpcI = 234;                      // can't modify the value cpcI points to (bc of first const)
    //cpcI = &sal;                      // can't redefine what a pointer of type int* const points to
    //*cpcI = 7623;                     // can't modify the value cpcI points to (bc of first const)
    
    cout << endl;
    
    // Task 16
    cout << "Task 16\n";
    // Pointers to user-defined types.  Add the type for struct Complex above.
    // Add code here
    Complex c = {11.23,45.67};      
    Complex* pC(&c);

    // cout << "real: " << *pC.real << "\nimaginary: " << *pC.img << endl;
    // expression must have class type but it has type "Complex *"
    cout << "real: " << pC->real << "\nimaginary: " << pC->img << endl;
    
    cout << endl;
    
    // Task 17
    cout << "Task 17\n";
    // Add code here
    // What is this code doing?
    PlainOldClass poc;
    PlainOldClass* ppoc( &poc );
    cout << ppoc->getX() << endl;
    ppoc->setX( 2837 );
    cout << ppoc->getX() << endl;
      
    cout << endl;

    // Task 18
    cout << "Task 18\n";
    // Test the changes to PlainOldClass
    PlainOldClassV2 poc2;
    PlainOldClassV2* ppoc2( &poc2 );
    cout << ppoc2->getX() << endl;
    ppoc2->setX( 2837 );
    cout << ppoc2->getX() << endl;
     
    cout << endl;
    
    // Task 19
    cout << "Task 19\n";
    // creating and modifying an item on the heap. Use the debugger to
    // observe.
    // Add code here
    int* pDyn = new int(3); // p points to an int initialized to 3 on the heap      
    *pDyn = 17;
    cout << "The " << *pDyn
     << " is stored at address " << pDyn
     << " which is in the heap\n";

    cout << endl;

    // Task 20
    cout << "Task 20\n";
    // What happens to pDyn in the following? With most compilers it
    // is unchanged.  Visual Studio actually changes it. (I should
    // check if that is just in debug mode.)
    // Add code here
    cout << pDyn << endl;  
    delete pDyn;  
    cout << pDyn << endl;
    cout << "The 17 might STILL be stored at address " << pDyn<< " even though we deleted pDyn\n";  
    cout << "But can we dereference pDyn?  We can try.  This might crash... " << *pDyn << ".  Still here?\n";

    cout << endl;

    // Task 21
    cout << "Task 21\n";
    // Add code here
    pDyn = nullptr;
    double* pDouble = nullptr;

    // Task 22
    cout << "Task 22\n";
    // Add code here
    // cout << "Can we dereference nullptr?  " << *pDyn << endl;      
    // cout << "Can we dereference nullptr?  " << *pDouble << endl;

    // Task 23
    cout << "Task 23\n";
    // Question. Can <code>this</code> be nullptr?
        //the "this" pointer can never be nullptr because it's the address of the object that a method is invoked on

    // Task 24
    cout << "Task 24\n";
    // Add code here
    double* pTest = new double(12);      
    delete pTest;      
    pTest = nullptr;      
    delete pTest; // safe

    // Task 25
    cout << "Task 25\n";
    // Add code here
    short* pShrt = new short(5);      
    delete pShrt;      
    // delete pShrt;

    // Task 26
    cout << "Task 26\n";
    // Add code here
    /*
    long jumper = 12238743;      
    delete jumper;                            
    long* ptrTolong = &jumper;      
    delete ptrTolong;  // What happens here?
    Complex cmplx;      
    delete cmplx;      // What happens here?        
    */
    
    // Task 27
    cout << "Task 27\n";
    // Add code here
    vector<Complex*> complV; // can hold pointers to Complex objects
    Complex* tmpPCmplx;      // space for a Complex pointer
    for (size_t ndx = 0; ndx < 3; ++ndx) {
    tmpPCmplx = new Complex; // create a new Complex object on the heap
    tmpPCmplx->real = ndx;   // set real and img to be the
    tmpPCmplx->img  = ndx;   // value of the current ndx
    complV.push_back(tmpPCmplx); // store the ADDRESS of the object in a vector or pointer to Complex
    }      
    // display the objects using the pointers stored in the vector
    for (size_t ndx = 0; ndx < 3; ++ndx) {         
        cout << complV[ ndx ]->real << endl;         
        cout << complV[ ndx ]->img  << endl;      
    }      
    // release the heap space pointed at by the pointers in the vector      
    for (size_t ndx = 0; ndx < 3; ++ndx) {         
        delete complV[ndx];
    }      
    // clear the vector      
    complV.clear();

    cout << endl;

    // Task 28 Use the Colour class
    cout << "Task 28\n";
    // Add Colour class above main
    // Add code here
    vector<Colour*> colours;         
    string inputName;       
    unsigned inputR, inputG, inputB;

    // fill vector with Colours from the file       
    // this could be from an actual file but here we are using the keyboard instead of a file
    // (so we don't have to create an actual file)
    // Do you remember the keystroke combination to indicate "end of file" at the keyboard?
    // somehow the while's test has to fail - from keyboard input
    while (cin >> inputName >> inputR >> inputG >> inputB) {
        colours.push_back(new Colour(inputName, inputR, inputG, inputB));       
    }         

    // display all the Colours in the vector:       
    for (size_t ndx = 0; ndx < colours.size(); ++ndx) {            
        colours[ndx]->display();            
        cout << endl;       
    }
    
    cout << endl;

    // Task 29 Use SpeakerSystem and Amplifier classes
    cout << "Task 29\n";
    // Add SpeakerSystem and Amplifier classes above main
    SpeakerSystem speakers1;
    SpeakerSystem speakers2;

    Amplifier amp1;
    Amplifier amp2;

    amp1.attachSpeakers(speakers1);
    amp2.attachSpeakers(speakers2);

    amp1.playMusic();
    amp2.playMusic();

    amp1.detachSpeakers();
    amp2.detachSpeakers();

    amp1.playMusic();
    amp2.playMusic();

    cout << endl;

    // Task 30 Use the Person class
    cout << "Task 30\n";
    // Add Person class above main
    // Add code here
    // write code to model two people in this world       
    Person joeBob("Joe Bob"), billyJane("Billy Jane");         

    // now model these two becoming roommates       
    joeBob.movesInWith(billyJane);         

    // did this work out?       
    cout << joeBob.getName() << " lives with " << joeBob.getRoomiesName() << endl;
    cout << billyJane.getName() << " lives with " << billyJane.getRoomiesName() << endl;
}



// dangling pointer: pointer still pointing to the memory address where the data has been deleted

//SUMMARY:
    //const int* pcI: non-constant pointer to a constant integer -- can change what it points to but cannot modify the value of the int it points to
    //int* const cpI: constant pointer to a non-constant integer -- cannot change what it points to after initialization, needs a default initialization value
    //const int* const cpcI: constant pointer to a constant integer -- cannot change what it points to after initialization, 
        //cannot modify the value of the int it points to, also needs a default initialization value
