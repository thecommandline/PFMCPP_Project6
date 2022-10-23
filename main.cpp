/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
    Not every pointer can be converted.
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.

    You have to ask yourself if each pointer can be converted to a (const) reference.
    Think carefully when making your changes.

 2) revise the 'else' statement in main() that handles when `smaller` is a nullptr. 
 there is only one reason for `compare` to return nullptr. 
 Update this std::cout expression to specify why nullptr was returned.
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>
struct T
{
    T(int v, const char* n) : value(v), name(n){}
    int value;
    std::string name;
};

struct Compare
{
    T* compare(T* a, T* b)
    {
        if(a != nullptr && b != nullptr)
        {
            if( a->value < b->value ) return a;
            if( a->value > b->value ) return b;
        }
        return nullptr;
    }
};

struct U
{
    float itemA { 0 }, itemB { 0 };
    float update(float* updatedValue)
    {
        if (updatedValue != nullptr)
        {
            std::cout << "U's itemA value: " << this->itemA << std::endl;
            this->itemA = *updatedValue;
            std::cout << "U's itemA updated value: " << this->itemA << std::endl;
            std::cout << "U's itemB value: " << this->itemB << std::endl;
            while(std::abs(this->itemB - this->itemA) > 0.001f)
            {
                this->itemB += 0.1f;
            }
            std::cout << "U's itemB updated value: " << this->itemB << std::endl;
            return this->itemB * this->itemA;
        }
        std::cout << "Error: 'update' function called with nullptr." << std::endl;
        return -1.f;
    }
};

struct Update
{
    static float staticUpdate(U* that, float* updatedValue )
    {
        if (that != nullptr && updatedValue != nullptr)
        {
            std::cout << "U's itemA value: " << that->itemA << std::endl;
            that->itemA = *updatedValue;
            std::cout << "U's itemA updated value: " << that->itemA << std::endl;
            std::cout << "U's itemB value: " << that->itemB << std::endl;
            while( std::abs(that->itemB - that->itemA) > 0.001f)
            {
                /*
                 write something that makes the distance between that->itemB and that->itemA get smaller
                 */
                that->itemB += 0.1f;
            }
            std::cout << "U's itemB updated value: " << that->itemB << std::endl;
            return that->itemB * that->itemA;
        }
        std::cout << "Error: 'staticUpdate' function called with nullptr." << std::endl;
        return -1.f;
    }
};
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T t1( 8, "Thing1");
    T t2( 7, "Thing2");
    
    Compare f;
    auto* smaller = f.compare(&t1,&t2);
    if (smaller != nullptr)
    {
        std::cout << "the smaller one is << " << smaller->name << std::endl;
    }
    else
    {
        std::cout << "Error: One or more T objects have the same 'value'." << std::endl;
    }
    
    std::cout << std::endl;
    U u1;
    float updatedValue = 5.f;
    std::cout << "[static func] u1's multiplied values: \n" << Update::staticUpdate(&u1, &updatedValue) << std::endl;
    
    std::cout << std::endl;
    U u2;
    std::cout << "[member func] u2's multiplied values: \n" << u2.update( &updatedValue ) << std::endl;
}
