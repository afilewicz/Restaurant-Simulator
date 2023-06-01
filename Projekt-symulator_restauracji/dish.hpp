#pragma once
#include <string>

using time_ = unsigned int;

class MenuItem;

class Dish {
    private:
        std::string name;
        time_ time_to_prepare;
        bool is_ready;
    public:
        Dish(MenuItem&);
        std::string get_name() const;
        time_ get_time_to_prepare() const;
        bool get_is_ready() const;
        void switch_is_ready();
};