#ifndef __Table_H__
#define __Table_H__

#include <string>
#include <array>
#include <vector>

namespace EmployeeDB::Model {
    class Table {
    public:
        void setAttributesVector(const std::vector<std::array<std::string, 3>>& attributesVector) {
            m_AttributesVector = attributesVector;
        }
        void setForeignKeysVector(const std::vector<std::array<std::string, 4>>& foreignKeysVector) {
            m_ForeignKeysVector = foreignKeysVector;
        }
        void setTableName(const std::string& tableName) {
            m_TableName = tableName;
        }

        const std::vector<std::array<std::string, 3>>& getAttributesVector() const {
            return m_AttributesVector;
        }
        const std::vector<std::array<std::string, 4>>& getForeignKeysVector() const {
            return m_ForeignKeysVector;
        }
        const std::string& getTableName() const {
            return m_TableName;
        }
    private:
        std::vector<std::array<std::string, 3>> m_AttributesVector;
        std::vector<std::array<std::string, 4>> m_ForeignKeysVector;
        std::string m_TableName;
    };
}

#endif 