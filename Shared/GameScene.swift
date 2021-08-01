//
//  GameScene.swift
//  nomikop
//
//  Created by Fabian Kropfhamer on 30.07.21.
//

import Foundation
import SpriteKit


class GameScene: SKScene {
    var label: SKLabelNode?
    var background: SKSpriteNode?
    var state: GameState?
    var controller: GameController?
    
    override func didMove(to view: SKView) {
        let state = GameState()
        self.state = state
        controller = GameController(state: state)
        
        self.backgroundColor = .blue
        
        label = SKLabelNode(text: "nomikop")
        
        
        let a = SKSpriteNode(color: .brown, size: CGSize(width: 32, height: 64))
        let b = SKSpriteNode(color: .red, size: CGSize(width: 32, height: 64))
        b.position = CGPoint(x: 64, y: 64)
        background = SKSpriteNode(color: .green, size: CGSize(width: 5 * 32, height: 10 * 32))
        background?.addChild(b)
        self.anchorPoint = CGPoint(x: 0.5, y: 0.5)
        self.addChild(background!)
        self.addChild(label!)
        self.addChild(a)
        
        print("didMove")
    }
    
    override func didChangeSize(_ oldSize: CGSize) {
        print(self.size)
    }
    
    override func update(_ currentTime: TimeInterval) {
        print("update")
    }
    
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
            default:
                break
            }
        }
        
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
            state!.position.y -= 1
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
}
