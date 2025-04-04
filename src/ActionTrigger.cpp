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