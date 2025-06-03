#include "StudentNode.h"

StudentNode::StudentNode(int score, const std::string& name)
    : mScore(score)
    , mName(name)
    , mNext(nullptr)
{
}
