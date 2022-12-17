#include <iostream>
#include <vector>

class GraphicObject
{
public:
    virtual void Draw() = 0;
};

class Circle : public GraphicObject
{
public:
    Circle( double radius )
    {
        fRadius = radius;
    }

    virtual void Draw() override
    {
        std::cout << "Drawing a circle with radius of " << fRadius << "\n";
    }

private:
    double fRadius;
};

class Square : public GraphicObject
{
public:
    Square( double side )
    {
        fSide = side;
    }

    virtual void Draw() override
    {
        std::cout << "Drawing a square with side of " << fSide << "\n";
    }

private:
    double fSide;
};

class Group : public GraphicObject
{
public:
    Group( const std::string& name, const std::vector<GraphicObject*>& objects )
    {
        fName       = name;
        fObjects    = objects;
    }

    virtual void Draw() override
    {
        std::cout << "Drawing a group with " << fObjects.size() << " objects\n";
        for ( const auto& obj : fObjects )
        {
            obj->Draw();
        }
    }

private:
    std::string                 fName;
    std::vector<GraphicObject*> fObjects;
};

int main()
{
    Circle c1( 3.14 );
    Circle c2( 5.55 );
    Square s1( 3 );
    std::vector<GraphicObject*> firstGroupObjs;
    firstGroupObjs.push_back( &c1 );
    firstGroupObjs.push_back( &s1 );
    Group firstGroup( "First Group", firstGroupObjs );

    std::vector<GraphicObject*> secondGroupObjs;
    secondGroupObjs.push_back( &c2 );
    secondGroupObjs.push_back( &firstGroup );
    Group secondGroup( "First Group", secondGroupObjs );
    secondGroup.Draw();
}