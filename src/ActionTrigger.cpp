#include "ActionTrigger.h"

/// @brief Triggers all actions with given payloads
/// @param Actions The map of actors and a map of their given actions and payloads
/// @param executeImmediately If true, actions are executed immediately instead of being added to the queue
/// @return True on success
bool ActionTrigger::triggerActions(std::map<String, std::map<String, String>> Actions, bool executeImmediately) {
	if (actions_config.Enabled) {
		for (const auto& actor : Actions) {
			for (const auto& action : actor.second ) {
				if (!executeImmediately) {
					if (!ActorManager::addActionToQueue(actor.first, action.first, action.second)){
						return false;
					}
				} else {
					if (std::get<1>(ActorManager::processActionImmediately(actor.first, action.first, action.second)).indexOf(R"("success": false)") != -1){
						return false;
					}
				}
			}
		}
		return true;
	} else {
		return false;
	}
}

/// @brief Returns a collection of all actors and actions available
/// @return A map with each actor and it's available action names and IDs
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
