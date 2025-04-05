#include "ActionTrigger.h"

/// @brief Triggers all actions with given payloads
/// @return True on success
bool ActionTrigger::triggerActions(std::map<String, std::map<String, String>> payloads) {
	for (const auto& actor : actions_config.Actions) {
		for (const auto& action : actor.second ) {
			if (!ActorManager::addActionToQueue(actor.first, action, payloads[actor.first][action])){
				return false;
			}
		}
	}
	return true;
}

/// @brief Returns a collections of all actors and actions available
/// @return A map with eacha actor and it's avaialble action names and IDs
std::map<String, std::map<int, String>>  ActionTrigger::listAllActions() {
	std::vector<Actor*> actors = ActorManager::getActors();
	std::map<String, std::map<int, String>> output;
	for (int i = 0; i < actors.size(); i++) {
		std::map<int, String> actions;
		for (auto const &a : actors[i]->Description.actions) {
			actions[a.second] = a.first;
		}
		output[actors[i]->Description.name] = actions;
	}
	return output;
}
