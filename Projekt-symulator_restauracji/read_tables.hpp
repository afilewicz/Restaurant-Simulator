#pragma once
#include <map>
#include <string>

template <typename Table>
void read_tables_from_csv(std::string file_path, std::map<uint32_t, Table> &tables)
{
    rapidcsv::Document doc(file_path, rapidcsv::LabelParams(0, -1));
    for (size_t i = 0; i < doc.GetRowCount(); i++)
    {
        uint32_t table_id = doc.GetCell<uint32_t>("Table_id", i);
        uint32_t num_of_seats = doc.GetCell<uint32_t>("Seats", i);
        tables[table_id] = Table{num_of_seats};
    }
}