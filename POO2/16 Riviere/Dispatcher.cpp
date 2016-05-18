//
// Created by Nykros on 19.05.2016.
//

#include "Dispatcher.h"

void Dispatcher::dispatch(const Father&) {}

void Dispatcher::dispatch(const Mother&) {}

void Dispatcher::dispatch(const Child&) {}

void Dispatcher::dispatch(const Thief&) {}

void Dispatcher::dispatch(const Cop&) {}

void Dispatcher::dispatch(const FamilyMember&) {

}

void ThiefDispatcher::dispatch(const FamilyMember&) {
	_fm = true;
}

void ThiefDispatcher::dispatch(const Cop&) {
	_cop = true;
}