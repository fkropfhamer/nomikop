//
//  FightScene.swift
//  nomikop
//
//  Created by Fabian Kropfhamer on 01.08.21.
//

import Foundation
import SpriteKit
import SwiftUI

class FightScene: SKScene {
    @ObservedObject var gameState: GameState
    var state = FightState()
    
    var actionMenu: SKSpriteNode?
    var attackMenu: SKSpriteNode?
    
    init(gameState: GameState) {
        self.gameState = gameState
        super.init(size: CGSize(width: 1000, height: 700))
        
        scaleMode = .aspectFit
    }
    
    required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    override func didMove(to view: SKView) {
        backgroundColor = .red
        
        let coverSprite = SKSpriteNode(color: .black, size: size)
        initialRender()
        
        anchorPoint = CGPoint(x: 0.5, y: 0.5)
        addChild(coverSprite)
        
        let fadeOutAction = SKAction.fadeOut(withDuration: 2)
        coverSprite.run(fadeOutAction, completion: afterFadeIn)
    }
    
    func afterFadeIn() {
        state.isProcessing = false
    }
    
    func createStatusBar(creature: Creature) -> SKSpriteNode {
        let lifeBar = createLifeBar(health: creature.health, maxHealth: creature.maxHealth)
        lifeBar.position = CGPoint(x: 100, y: -50)
        
        let label = SKLabelNode(text: "\(creature.name) \(creature.health)/\(creature.maxHealth) ")
        label.fontColor = .black
        
        let background = SKSpriteNode(color: .cyan, size: CGSize(width: 250, height: 150))
        
        background.addChild(lifeBar)
        background.addChild(label)
        
        return background
    }
    
    func createLifeBar(health: Int, maxHealth: Int) -> SKSpriteNode {
        let maxWidth = 200
        let height = 10
        
        let healthPortion = Float(health) / Float(maxHealth)
        let widthPortion = healthPortion * Float(maxWidth)
        
        print(widthPortion, healthPortion)
        
        let fullLifeBar = SKSpriteNode(color: .brown, size: CGSize(width: maxWidth, height: height))

        let lifeBar = SKSpriteNode(color: .blue, size: CGSize(width: Int(ceil(widthPortion)), height: height))
        
        lifeBar.anchorPoint = CGPoint(x: 1.0, y:0.5)
        
        fullLifeBar.anchorPoint = CGPoint(x: 1.0, y: 0.5)
        fullLifeBar.addChild(lifeBar)
        
        return fullLifeBar;
    }
    
    func createActionMenu() -> SKSpriteNode {
        let actionMenu = SKSpriteNode(color: .darkGray, size: CGSize(width: 250, height: 100))
        
        let attackAction = SKLabelNode(text: "Action")
        
        actionMenu.addChild(attackAction)
        
        return actionMenu
    }
    
    func createAttackMenu() -> SKSpriteNode {
        let attackMenu = SKSpriteNode(color: .darkGray, size: CGSize(width: 250, height: 100))
        
        let attackAction = SKLabelNode(text: "Attack")
        
        attackMenu.addChild(attackAction)
        
        return attackMenu
    }
    
    func initialRender() {
        let c = Creature(name: "Haha", attacks: [], health: 90, maxHealth: 100)
        let cc = Creature(name: "😝😜😝", attacks: [], health: 90, maxHealth: 500)
        let s = createStatusBar(creature: c)
        let ss = createStatusBar(creature: cc)
        s.position = CGPoint(x: 300, y: -200)
        ss.position = CGPoint(x: -250, y: 200)
        
        actionMenu = createActionMenu()
        actionMenu!.position = CGPoint(x: -250, y: -200)
        addChild(actionMenu!)
        
        attackMenu = createAttackMenu()
        attackMenu!.position = CGPoint(x: -250, y: -200)
        attackMenu!.isHidden = true
        addChild(attackMenu!)
        
        
        
        addChild(s)
        addChild(ss)
       
    }
    
    func hideActionMenu() {
        if let menu = actionMenu {
            menu.isHidden = true
        }
    }
    
    func showActionMenu() {
        if let menu = actionMenu {
            menu.isHidden = false
        }
    }
    
    func hideAttackMenu() {
        if let menu = attackMenu {
            menu.isHidden = true
        }
    }
    
    func showAttackMenu() {
        if let menu = attackMenu {
            menu.isHidden = false
        }
    }
    
    func actionButtonPressed() {
        if (state.menu == .Action) {
            state.menu = .Attack
            hideActionMenu()
            showAttackMenu()
        }
    }
    
    func backButtonPressed() {
        if (state.menu == .Action) {
            return
        }
        
        if (state.menu == .Attack) {
            state.menu = .Action
            hideAttackMenu()
            showActionMenu()
        }
    }
    
    #if os(macOS)
    override func keyDown(with event: NSEvent) {
        if (state.isProcessing) {
            return
        }
        switch (event.keyCode) {
        case Key.m:
            gameState.mode = .outside
            break
        case Key.Enter:
            actionButtonPressed()
            break
        case Key.b:
            backButtonPressed()
        break
        default:
            break
        }
        
        print(event.keyCode)
    }
    #endif
}
