//
//  FightController.swift
//  nomikop
//
//  Created by Fabian Kropfhamer on 07.08.21.
//

import Foundation

class FightController {
    var view: FightScene
    var gameState: GameState
    
    init(gameState: GameState, fightView: FightScene) {
        view = fightView
        self.gameState = gameState
    }    
}
