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
			/// @brief Whether to enable triggering or not
			bool Enabled = false;			
		} actions_config;

		bool triggerActions(std::map<String, std::map<String, String>> Actions, bool executeImmediately = false);

		std::map<String, std::map<int, String>> listAllActions();
};