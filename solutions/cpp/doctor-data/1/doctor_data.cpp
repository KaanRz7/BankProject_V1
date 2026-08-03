// ERROR: FILE CORRUPTED. Please supply valid C++ Code.
#include "doctor_data.h"

namespace heaven{
    std::string get_older_bob(Vessel bob1,Vessel bob2){
        if (bob1.generation<=bob2.generation){
            return bob1.name;
        }
        return bob2.name;
    }
    bool in_the_same_system(Vessel bob1,Vessel bob2){
        if (bob1.current_system==bob2.current_system){
            return true;
        }
        return false;
    }
}
