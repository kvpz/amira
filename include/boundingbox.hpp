#ifndef BOUNDINGBOX_HPP
#define BOUNDINGBOX_HPP

class BoundingBox {
public:
    BoundingBox() = default;
    BoundingBox(XYPoint<int> _xy1, XYPoint<int> _xy2, ObjectType _objectType, double distance)
    : xy1(_xy1), xy2(_xy2), objectType(_objectType), distanceFromCamera(distance)
    {}
    
    BoundingBox(const BoundingBox& bbox) 
    : xy1(bbox.xy1), xy2(bbox.xy2), objectType(bbox.objectType), distanceFromCamera(bbox.distanceFromCamera)
    {
        std::cout << "in copy constructor" << std::endl;
        std::cout << "(BoundingBox) xy1 " << xy1 << "\n";
        std::cout << "(BoundingBox) xy2 " << xy2 << "\n";
        std::cout << "(BoundingBox) objectType " << objectType.toString() << "\n";
        std::cout << "(BoundingBox) distanceFromCamera " << distanceFromCamera << std::endl;

    }

    BoundingBox& operator=(const BoundingBox& bbox) 
    {
        std::cout << "in copy constructor(=)" << "\n";
        std::cout << "(BoundingBox=) xy1 " << xy1 << "\n";
        std::cout << "(BoundingBox=) xy2 " << xy2 << "\n";
        std::cout << "(BoundingBox=) objectType " << objectType.toString() << "\n";
        std::cout << "(BoundingBox=) distanceFromCamera " << distanceFromCamera << std::endl;        
        if(this != &bbox) {
            xy1 = bbox.xy1;
            xy2 = bbox.xy2;
            objectType = bbox.objectType;
            distanceFromCamera = bbox.distanceFromCamera;
        }

        return *this;
    }

    //override operator=(const BoundingBox& bbox) 
    //: xy1(bbox.xy1), xy2(bbox.xy2), objectType(bbox.objectType) 
    //{}


    bool compare(const BoundingBox& a, const BoundingBox& b) const {
        return a.xy1.getX() < b.xy1.getX();
    }

    bool operator<(const BoundingBox& a) const {
        return xy1.getX() < a.xy1.getX();
    }

    XYPoint<int> getCenterXY() {
        int xpoint = xy1.getX() + ((xy2.getX() - xy1.getX()) / 2);
        int ypoint = xy1.getY() + ((xy2.getY() - xy1.getY()) / 2);
        return XYPoint<int>(xpoint, ypoint);
    }   

    XYPoint<int> getXY1() { return xy1; }
    XYPoint<int> getXY2() { return xy2; }

    ObjectType getObjectType() { return objectType; }

    double getDistanceFromCamera() { return distanceFromCamera; }
    
private:
            
    XYPoint<int> xy1;
    XYPoint<int> xy2;
    ObjectType objectType;
    double distanceFromCamera;
};

struct BoundingBoxCompare {
    bool operator()(const BoundingBox& a, const BoundingBox& b) const {
        //return a.xy1.getX() < b.xy1.getX();
        return a < b;
    }
};

#endif