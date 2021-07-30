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
    var scene: SKScene {
        let scene = GameScene()
        scene.scaleMode = .resizeFill
        
        return scene
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
