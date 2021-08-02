//
//  GameScene.swift
//  nomikop
//
//  Created by Fabian Kropfhamer on 30.07.21.
//

import Foundation
import SpriteKit


class OutsideScene: SKScene {
    var label: SKLabelNode?
    var background: SKSpriteNode?
    var gameState: GameState
    var controller: GameController?
    
    init(gameState: GameState) {
        self.gameState = gameState
        super.init(size: CGSize(width: 0, height: 0))
        
        scaleMode = .resizeFill
    }
    
    required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    override func didMove(to view: SKView) {
        self.backgroundColor = .blue
        
        label = SKLabelNode(text: "nomikop")
        
        
        let a = SKSpriteNode(color: .brown, size: CGSize(width: 32, height: 64))
        let b = SKSpriteNode(color: .red, size: CGSize(width: 32, height: 64))
        b.position = CGPoint(x: 64, y: 64)
        background = SKSpriteNode(color: .green, size: CGSize(width: 5 * 32, height: 10 * 32))
        background?.addChild(b)
        anchorPoint = CGPoint(x: 0.5, y: 0.5)
        self.addChild(background!)
        self.addChild(label!)
        self.addChild(a)
        
        print("didMove")
    }
    
    override func didChangeSize(_ oldSize: CGSize) {
        print(self.size)
    }
    
    override func update(_ currentTime: TimeInterval) {
        //print("update")
    }
    
    #if os(macOS)
    override func keyDown(with event: NSEvent) {
        if let key = event.characters {
            switch key {
            case "w":
                moveUp()
                break
            case "a":
                moveLeft()
                break
            case "s":
                moveDown()
                break
            case "d":
                moveRight()
            case "m":
                gameState.mode = .fight
                break
            default:
                break
            }
        }
    }
    #endif
    
    func moveUp() {
        print("up")
        let action = SKAction.moveBy(x: 0, y: -32, duration: 0.1)
        label!.run(action);
        background!.run(action)
    }
    
    func moveDown() {
        let action = SKAction.moveBy(x: 0, y: 32, duration: 0.1)
        label!.run(action)
        background!.run(action)
        gameState.position.y -= 1
    }
    
    func moveRight() {
        let action = SKAction.moveBy(x: -32, y: 0, duration: 0.1)
        label!.run(action)
        background!.run(action)
    }
    
    func moveLeft() {
        let action = SKAction.moveBy(x: 32, y: 0, duration: 0.1)
        label!.run(action)
        background!.run(action)
    }
}
