#include "PersonProfile.h"

PersonProfile::PersonProfile(std::string name, std::string email) : m_name(name), m_email(email), size(0) {
}

std::string PersonProfile::GetName() const {
    return m_name;
}
std::string PersonProfile::GetEmail() const {
    return m_email;
}
void PersonProfile::AddAttValPair(const AttValPair& attval) {
    std::set<std::string>* s = traits.search(attval.attribute);
    if (s == nullptr) {
        std::set<std::string> s;
        s.insert(attval.value);
        traits.insert(attval.attribute, s);
        size++;
        attributes.push_back(AttValPair(attval.attribute, attval.value));
    }
    else {
        std::set<std::string>* s = traits.search(attval.attribute);
            long num = s->size();
            s->insert(attval.value);
            if (num != s->size()) {
                attributes.push_back(AttValPair(attval.attribute, attval.value));
            }
    }
}

int PersonProfile::GetNumAttValPairs() const {
    return attributes.size();
}

bool PersonProfile::GetAttVal(int attribute_num, AttValPair& attval) const {
    if (attribute_num < 0 || attribute_num >= size) {
        return false;
    }
    attval = attributes[attribute_num];
    return true;
}
