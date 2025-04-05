/*
* This file and associated .cpp file are licensed under the GPLv3 License Copyright (c) 2024 Sam Groveman
*
* Contributors: Sam Groveman
*/

#pragma once
#include <Arduino.h>
#include <ActorManager.h>
#include <map>
#include <vector>

/// @brief Allows for triggering of actions with payloads
class ActionTrigger {
	public:
		/// @brief Holds actions configuration
		struct {			
			/// @brief A set of actor names and action names to trigger
			std::map<String, std::vector<String>> Actions;

			/// @brief Whether to enable auto triggering or not
			bool Enabled;			
		} actions_config;

		bool triggerActions(std::map<String, std::map<String, String>> payloads);

		std::map<String, std::map<int, String>> listAllActions();
};