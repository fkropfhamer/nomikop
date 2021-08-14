//
//  FightState.swift
//  nomikop
//
//  Created by Fabian Kropfhamer on 14.08.21.
//

import Foundation

struct FightState {
    var isProcessing = true;
    var playerCreature = Creature(name: "PlayerCreature", attacks: [], health: 100, maxHealth: 500)
    var enemyCreatuer = Creature(name: "Enemy", attacks: [], health: 500, maxHealth: 100)
}
