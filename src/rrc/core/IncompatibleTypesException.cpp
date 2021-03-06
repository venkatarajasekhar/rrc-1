/**
 *  @autor arssivka
 *  @date 8/31/16
 */

#include <include/rrc/core/IncompatibleTypesException.h>
#include <include/rrc/core/MetaTable.h>
#include <sstream>


rrc::IncompatibleTypesException::IncompatibleTypesException(TypeId firstTypeId,
                                                            TypeId secondTypeId)
        : std::runtime_error("Types are incompatible"), mFirstTypeId(firstTypeId), mSeconTypeId(secondTypeId) { }

rrc::TypeId rrc::IncompatibleTypesException::getFirstTypeId() const {
    return mFirstTypeId;
}


rrc::TypeId rrc::IncompatibleTypesException::getSeconTypeId() const {
    return mSeconTypeId;
}
