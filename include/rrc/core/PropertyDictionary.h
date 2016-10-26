/**
 *  @autor tekatod
 *  @date 10/7/16
 */
#pragma once


#include "CopyOnWrite.h"
#include "Property.h"
#include <map>
#include <vector>

namespace rrc {
    /**
     * @brief This is a wrapper class of CopyOnWrite<std::map<string, Property>>. It is created to ease usage of
     * CopyOnWrite<std::map<string, Property>>.
     */
    class PropertyDictionary {
    public:

        /**
         * @brief Default constructor of PropertyDictionary.
         */
        PropertyDictionary() = default;

        /**
         * @brief Default move constructor of PropertyDictionary.
         * @param other Another PropertyDictionary instance to move from.
         */
        PropertyDictionary(PropertyDictionary&& other) = default;

        /**
         * @brief Default copy constructor of PropertyDictionary.
         * @param other Another PropertyDictionary instance to copy from.
         */
        PropertyDictionary(const PropertyDictionary& other) = default;

        /**
         * @brief Checks if this PropertyDictionary contains Property with specified name.
         * @param propertyName Name of the Property to check.
         * @return True if contains, otherwise false.
         */
        bool isContainsName(const std::string &propertyName) const;

        /**
         * @brief Checks if this dictionary doesn't contain any properties.
         * @return True if empty, otherwise false.
         */
        bool isEmpty() const;

        /**
         * @brief Returns Property with specified name.
         * @param propertyName Name of the property to get.
         * @return Property with the specified name.
         */
        Property getProperty(const std::string& propertyName);

        /**
         * @brief Returns names of the properties which this Dictionary contains.
         * @return vector<string> of names.
         */
        std::vector<std::string> getNames() const;

        /**
         * @brief Removes property with the specified name from the dictionary.
         * @param propertyName Name of the property to remove.
         */
        void removeProperty(const std::string& propertyName);

        /**
         * @brief Sets new or updates existing property in the dictionary.
         * @param propertyName Name of the property to update or create.
         * @param property Value to store in the property that can be of int, float, bool or string types. Or it can be Property instance.
         */
        template<class T>
        void addOrUpdateProperty(const std::string& propertyName, T&& property) {
            auto container = mDictionary->find(propertyName);
            if (container != mDictionary->end()) {
                container->second = std::forward<T>(property);
            } else {
                mDictionary->insert({propertyName, Property(std::forward<T>(property))});
            }
        }


        PropertyDictionary& operator= (const PropertyDictionary& other) = default;


        PropertyDictionary& operator= (PropertyDictionary&& other) = default;

    private:
        rrc::CopyOnWrite<std::map<std::string, Property>> mDictionary;
    };
}
