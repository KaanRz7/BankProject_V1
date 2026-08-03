#ifndef DOCTOR_DATA_H
#define DOCTOR_DATA_H
#include <string>

namespace star_map{
    enum class System{Sol,BetaHydri,EpsilonEridani,AlphaCentauri,DeltaEridani,Omicron2Eridani};
}

namespace heaven{
    class Vessel{
        public:
            std::string name;
            int generation;
            star_map::System current_system;
            int busters{0};

            Vessel(std::string name,int generation,star_map::System current_system=star_map::System::Sol){
                this->name=name;
                this->generation=generation;
                this->current_system=current_system;
            }
            Vessel replicate(std::string new_name){
                return Vessel(new_name,generation+1,current_system);
            }
            void make_buster(){
                ++busters;
            }
            bool shoot_buster(){
                if (busters==0){
                    return false;
                }
                --busters;
                return true;
            }
    };
    std::string get_older_bob(Vessel bob1,Vessel bob2);
    bool in_the_same_system(Vessel bob1,Vessel bob2);
}
#endif
