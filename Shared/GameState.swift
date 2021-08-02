//
//  Game.swift
//  nomikop
//
//  Created by Fabian Kropfhamer on 01.08.21.
//

import Foundation
import SpriteKit

enum GameMode {
    case outside
    case fight
}

class GameState : ObservableObject {
    var position: CGPoint
    
    @Published var mode: GameMode
    
    
    init() {
        position = CGPoint(x: 0, y: 0)
        mode = GameMode.outside
    }
}
