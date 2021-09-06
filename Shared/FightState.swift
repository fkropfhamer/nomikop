//
//  FightState.swift
//  nomikop
//
//  Created by Fabian Kropfhamer on 14.08.21.
//

import Foundation

enum FightMenu {
    case Action
    case Attack
}

struct FightState {
    var isProcessing = true;
    var playerCreature = Creature(name: "PlayerCreature", attacks: [attack1, attack2, attack3, attack4], health: 100, maxHealth: 500)
    var enemyCreatuer = Creature(name: "Enemy", attacks: [], health: 500, maxHealth: 100)
    var menu = FightMenu.Action
}
