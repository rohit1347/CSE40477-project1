/*
 * Vending Machine Project
 * CSE-40477
 *
 * Coin.cpp
 * YOU MUST IMPLEMENT THE FUNCTIONS IN THIS FILE.
 */
#include "Coin.h"

Project1::Coin::Coin(CoinType denomination)
    : denomination(denomination)
{
    // TODO: Implement
}

Project1::Coin::CoinType
Project1::Coin::getDenomination() const
{
    // TODO: Implement
    return denomination;
}

unsigned
Project1::Coin::getValueCents() const
{
    // TODO: Implement
    switch (denomination)
    {
    case COINTYPE_WOODEN_NICKEL:
        return 0;
    case COINTYPE_PENNY:
        return 1;
    case COINTYPE_NICKEL:
        return 5;
    case COINTYPE_DIME:
        return 10;
    case COINTYPE_QUARTER:
        return 25;
    case COINTYPE_HALF_DOLLAR:
        return 50;
    case COINTYPE_DOLLAR:
        return 100;
    default:
        return 0;
    }
}
