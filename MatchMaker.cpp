#include "MatchMaker.h"
MatchMaker::MatchMaker(const MemberDatabase& mdb, const AttributeTranslator& at) : m_mdb(mdb), m_at(at) {}

std::vector<EmailCount> MatchMaker::IdentifyRankedMatches(std::string email, int threshold) const {
    std::vector<EmailCount> v;
    return v;
}
