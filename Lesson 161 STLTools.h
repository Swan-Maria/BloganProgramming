#pragma once
#include <iostream>
#include <map>

template <typename KeyType, typename ValueType, typename Comparator = std::less<KeyType>>
void Show(const std::map<KeyType, ValueType, Comparator>& map)
{
    if (map.empty())
    {
        std::cout << "Container is empty!\n\n";
        return;
    }

    for (const auto& element : map)
    {
        const auto& key = element.first;
        const auto& value = element.second;

        std::cout << "[key = " << key << ", value = " << value << "]" << std::endl;
    }

    std::cout << std::endl;
}

template <typename KeyType, typename ValueType, typename Comparator = std::less<KeyType>>
void Show(const std::multimap<KeyType, ValueType, Comparator>& multimap)
{
    if (multimap.empty())
    {
        std::cout << "Container is empty!\n\n";
        return;
    }

    for (const auto& element : multimap)
    {
        const auto& key = element.first;
        const auto& value = element.second;

        std::cout << "[key = " << key << ", value = " << value << "]" << std::endl;
    }

    std::cout << std::endl;
}
