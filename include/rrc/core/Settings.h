/**
 *  @autor arssivka
 *  @date 7/8/16
 */

#pragma once

#include <string>
#include "TSLookUp.h"
#include "Property.h"

namespace rrc {
    class Settings {
    public:

        Settings(unsigned num);

        Settings();

        template <class D>
        void set(const std::string& key, D&& data) {
            mSettings.set(key, Property(std::forward<D>(data)));
        }

        void remove(const std::string& key);

        Property get(const std::string& key) const;

        bool contains(const std::string& key) const;


    private:
        TSLookUp<std::string, Property> mSettings;
    };
}


