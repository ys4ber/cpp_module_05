here we are talking about the exception 

the way that they works with , and the new concept that challenging me to solve this module.

first question that i have ask is what is excpetion in c++

imagine that we have a program of dividing two numbers

what i will do set protect that numbers from dividing by 0

i will try to divid and if i got 0 to divide to then i will divide by 0

thats it 

the throw function (i will call it function) takes a data that will throm

then the catch function (i will call it also function) takes the same data type that the throw

function takes

here is an example :

```
int main()
{
    int a = 23;
    try
    {
        if(a < 5)
            std::cout << "a is less than 5\n";
        else
        {
            throw("helloo sdfsf sdfsf sfsdf");
            std::cout << "heeeeeeeeeeere" << std::endl;
        }
        std::cout << "heere afrer try" << std::endl;   
    }
    catch(const char *b)
    {
       std::cout << "Caught an exception -- value is: " << a << std::endl;
    }
}

```
