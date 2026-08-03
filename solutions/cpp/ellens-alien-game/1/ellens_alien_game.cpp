namespace targets {
class Alien{
private:
    int health{3};
public:
    int x_coordinate{0};
    int y_coordinate{0};

    Alien(int x, int y) : x_coordinate{x}, y_coordinate{y} {}

    int get_health() const {
        return health;
    }

    bool hit() {
        if (health > 0) {
            --health;
            return true;
        }
        return false;    
    }

    bool is_alive() const {
        return health > 0;
    }

    bool teleport(int x_new, int y_new) {
        x_coordinate = x_new;
        y_coordinate = y_new;
        return true;
    }

    bool collision_detection(const Alien& other) const {
        if (x_coordinate==other.x_coordinate && y_coordinate==other.y_coordinate){
            return true;
        }
        else{
            return false;
        }
      // also can be: return x_coordinate == other.x_coordinate && y_coordinate == other.y_coordinate;                
    }         
};
}
