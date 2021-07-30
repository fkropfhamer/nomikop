//
//  GameScene.swift
//  nomikop
//
//  Created by Fabian Kropfhamer on 30.07.21.
//

import Foundation
import SpriteKit


class GameScene: SKScene {
    override func didMove(to view: SKView) {
        self.backgroundColor = .blue
        
        let label = SKLabelNode(text: "nomikop")
        
        self.anchorPoint = CGPoint(x: 0.5, y: 0.5)
        self.addChild(label)
    }
    
    override func didChangeSize(_ oldSize: CGSize) {
        print(self.size)
    }
}
