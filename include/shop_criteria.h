#ifndef GUARD_SHOP_CRITERIA_H
#define GUARD_SHOP_CRITERIA_H

void TryBuildDynamicShopItemList(const u16 **ogItemList, u16 *resultingTotal);
void TryFreeDynamicShopItemList(const u16 **ogItemList);

// Add new Criterias below!
bool32 ShopCriteria_HasPokedex(enum Item item);
bool32 ShopCriteria_ByBadges(enum Item item);

#endif // GUARD_SHOP_CRITERIA_H
