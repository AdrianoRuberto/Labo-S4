//
// Created by Nykros on 19.05.2016.
//

#include "Dispatcher.h"

void Dispatcher::dispatch(const Father&) { }

void Dispatcher::dispatch(const Mother&) { }

void Dispatcher::dispatch(const Cop&) { }

void Dispatcher::dispatch(const FamilyMember&) { }

void ThiefDispatcher::dispatch(const FamilyMember&) { _fm = true; }

void ThiefDispatcher::dispatch(const Cop&) { _cop = true; }

void ChildDispatcher::dispatch(const Father&) { _father = true; }

void ChildDispatcher::dispatch(const Mother&) { _mother = true; }
