//
//  ContentView.swift
//  Shared
//
//  Created by Fabian Kropfhamer on 30.07.21.
//

import SwiftUI
import CoreData
import SpriteKit

struct ContentView: View {
    @StateObject var gameState = GameState()
    
    var scene: SKScene {
        switch gameState.mode {
        case GameMode.outside:
            return OutsideScene(gameState: gameState)
        case .fight:
            return FightScene(gameState: gameState)
        }
    }
    
    var body: some View {
        SpriteView(scene: scene)
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView().environment(\.managedObjectContext, PersistenceController.preview.container.viewContext)
    }
}
