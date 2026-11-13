#include "global.h"
#include "item.h"
#include "script.h"
#include "event_data.h"
#include "malloc.h"
#include "shop_criteria.h"

static EWRAM_DATA const u16 *sDynamicShopItemListRef = NULL;

// Remove the UNUSED if you'll use the functions!
static UNUSED bool32 ShopCriteriaByBadgeCount(u32 count);
static UNUSED bool32 ShopCriteriaByFlag(u32 flagId);
static UNUSED bool32 ShopCriteriaByVar(u32 varId, u32 varValue);

void TryBuildDynamicShopItemList(const u16 **ogItemList, u16 *resultingTotal)
{
    sDynamicShopItemListRef = *ogItemList;

    u16 *list = AllocZeroed((*resultingTotal + 1) * sizeof(u16));
    u32 overallIdx = 0, idx = 0;

    while (idx < *resultingTotal)
    {
        enum Item item = sDynamicShopItemListRef[idx];

        if (IsItemShopCriteriaFulfilled(item))
        {
            list[overallIdx] = item;
            overallIdx++;
        }

        idx++;
    }

    list[overallIdx] = ITEM_NONE;

    *ogItemList = list;
    *resultingTotal = overallIdx;
}

void TryFreeDynamicShopItemList(const u16 **ogItemList)
{
    Free((u16 *)*ogItemList);
    *ogItemList = sDynamicShopItemListRef;
}

// Add new Criterias below!

static bool32 ShopCriteriaByBadgeCount(u32 count)
{
    u32 badgeCount = 0;

    for (u32 badgeFlag = FLAG_BADGE01_GET; badgeFlag < FLAG_BADGE01_GET + NUM_BADGES; badgeFlag++)
    {
        if (FlagGet(badgeFlag))
            badgeCount++;
    }

    if (badgeCount >= count)
        return TRUE;

    return FALSE;
}

bool32 ShopCriteria_ByBadges(enum Item item)
{
    switch (item)
    {
        case ITEM_AWAKENING:
        case ITEM_BURN_HEAL:
        case ITEM_ICE_HEAL:
            return ShopCriteriaByBadgeCount(1);
        case ITEM_GREAT_BALL:
        case ITEM_SUPER_POTION:
        case ITEM_ESCAPE_ROPE:
            return ShopCriteriaByBadgeCount(2);
        case ITEM_SUPER_REPEL:
        case ITEM_ABILITY_CAPSULE:
            return ShopCriteriaByBadgeCount(3);
        case ITEM_ULTRA_BALL:
        case ITEM_HYPER_POTION:
        case ITEM_REVIVE:
            return ShopCriteriaByBadgeCount(4);
        case ITEM_FULL_HEAL:    
        case ITEM_MAX_REPEL:
        case ITEM_ABILITY_PATCH:
            return ShopCriteriaByBadgeCount(5);
        case ITEM_MAX_POTION:
            return ShopCriteriaByBadgeCount(7);
        case ITEM_FULL_RESTORE:            
            return ShopCriteriaByBadgeCount(8);
            //return ShopCriteriaByBadgeCount(1);
        default:
            return TRUE;
    }
}

// These two below are somewhat identical to ShopCriteriaByBadgeCount
// but uses only one specific event var/flag check. Useful if you need
// a specific badge flag instead of just the badge total.

static bool32 ShopCriteriaByFlag(u32 flagId)
{
    if (FlagGet(flagId))
        return TRUE;

    return FALSE;
}

bool32 ShopCriteria_HasPokedex(enum Item item)
{
    return ShopCriteriaByFlag(FLAG_RECEIVED_POKEDEX_FROM_BIRCH);
}

static UNUSED bool32 ShopCriteriaByVar(u32 varId, u32 varValue)
{
    if (VarGet(varId) >= varValue)
        return TRUE;

    return FALSE;
}
