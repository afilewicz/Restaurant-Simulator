#pragma once
#include <string>
#include "rapidcsv.h"
#include "table_id.hpp"

void read_time_to_prepare(std::string file_path, std::map<std::string, time_> &time_to_prepare)
{
    rapidcsv::Document doc(file_path, rapidcsv::LabelParams(0, -1));
    for (size_t i = 0; i < doc.GetRowCount(); i++)
    {
        std::string dish_name = doc.GetCell<std::string>("Dish", i);
        time_ preparing_time = doc.GetCell<time_>("Time_to_prepare", i);
        time_to_prepare[dish_name] = preparing_time;
    }
}