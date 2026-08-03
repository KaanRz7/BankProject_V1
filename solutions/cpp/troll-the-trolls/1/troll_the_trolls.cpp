namespace hellmath {

// TODO: Task 1 - Define an `AccountStatus` enumeration to represent the four
// account types: `troll`, `guest`, `user`, and `mod`.
// TODO: Task 1 - Define an `Action` enumeration to represent the three
// permission types: `read`, `write`, and `remove`.
    enum AccountStatus{
    troll,
    guest,
    user,
    mod
    };
    enum Action{
    read,
    write,
    remove
    };
    
// TODO: Task 2 - Implement the `display_post` function, that gets two arguments
// of `AccountStatus` and returns a `bool`. The first argument is the status of
// the poster, the second one is the status of the viewer.
    bool display_post(AccountStatus poster,AccountStatus viewer){
        if (poster==AccountStatus::troll && viewer!=AccountStatus::troll){
            return false;
        }
        return true;
    }




    

// TODO: Task 3 - Implement the `permission_check` function, that takes an
// `Action` as a first argument and an `AccountStatus` to check against. It
// should return a `bool`.
    bool permission_check(Action element1,AccountStatus element2 ){
        if (element2==AccountStatus::mod || element1==Action::read){
            return true;
        }
        else if ((element2==AccountStatus::user || element2==AccountStatus::troll) && (element1==Action::read || element1==Action::write)){
            return true;
        }
        return false;
    }

// TODO: Task 4 - Implement the `valid_player_combination` function that
// checks if two players can join the same game. The function has two parameters
// of type `AccountStatus` and returns a `bool`.
    bool valid_player_combination(AccountStatus user_type1,AccountStatus user_type2){
        if (user_type1==AccountStatus::guest || user_type2==AccountStatus::guest){
            return false; 
        }
        else if ((user_type1!=AccountStatus::troll && user_type2==AccountStatus::troll)||(user_type1==AccountStatus::troll && user_type2!=AccountStatus::troll)){ 
            return false;
        }
        return true;
    }
    
    

// TODO: Task 5 - Implement the `has_priority` function that takes two
// `AccountStatus` arguments and returns `true`, if and only if the first
// account has a strictly higher priority than the second.
    bool has_priority(AccountStatus type1,AccountStatus type2){
        if ((type1==AccountStatus::mod || type2==AccountStatus::troll) && (type1!=type2)){
            return true;
        }
        else if (type1==AccountStatus::user && type2==AccountStatus::guest){
            return true;
        }
        return false;
    }

}  // namespace hellmath
