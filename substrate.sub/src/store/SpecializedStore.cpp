#include "SpecializedStore.h"


SpecializedStore::SpecializedStore(const LocalStore& store)
: QObject(NULL)
, _store(store)
{
}
