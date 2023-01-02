#include <iostream>
class Toy
{
private:
    std::string name;
public:
    Toy (std::string outName): name(outName) {};
    Toy() : name("SomeToyName") {};
    std::string getName () {return name;}
};
class shared_ptr_toy
{
private:
    Toy *object;
    size_t *count;
public:
    shared_ptr_toy():count(new size_t (1)){}

    shared_ptr_toy& operator=(const shared_ptr_toy& other)
    {
        if (this==&other)
            return *this;
        if (object!= nullptr)
            delete object;
        object = new Toy (*other.object);
        *count=*(other.count)+1;
        return *this;
    }
    shared_ptr_toy(const shared_ptr_toy& other):object(other.object),count(other.count)
    {
        *count++;
    }
    ~shared_ptr_toy()
    {
        *count--;
        if ((*count)==0)
    delete object;
    }
    Toy& make_shared_toy(std::string nameToy)
    {
        Toy* Toys = new Toy(nameToy);
        return  *Toys;
    }
    Toy& make_shared_toy(Toy& OtherToy)
    {

        Toy* Toys = new Toy(OtherToy.getName());
        return *Toys;
    }
};
int main() {
    return 0;
}
