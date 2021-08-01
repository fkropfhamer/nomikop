//
//  FightScene.swift
//  nomikop
//
//  Created by Fabian Kropfhamer on 01.08.21.
//

import Foundation
import SpriteKit

class FightScene: SKScene {
    var gameState: GameState
    
    init(gameState: GameState) {
        self.gameState = gameState
        super.init(size: CGSize(width: 0, height: 0))
        
        scaleMode = .resizeFill
    }
    
    required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    override func didMove(to view: SKView) {
        backgroundColor = .red
        
        let coverSprite = SKSpriteNode(color: .black, size: size)
        
        let label = SKLabelNode(text: "Fight")
        
        
        anchorPoint = CGPoint(x: 0.5, y: 0.5)
        addChild(label)
        addChild(coverSprite)
        
        let fadeOutAction = SKAction.fadeOut(withDuration: 2)
        coverSprite.run(fadeOutAction)
    }
    
    override func keyDown(with event: NSEvent) {
        gameState.mode = .outside
    }
}
