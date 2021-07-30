//
//  nomikopApp.swift
//  Shared
//
//  Created by Fabian Kropfhamer on 30.07.21.
//

import SwiftUI

@main
struct nomikopApp: App {
    let persistenceController = PersistenceController.shared

    var body: some Scene {
        WindowGroup {
            ContentView()
                .environment(\.managedObjectContext, persistenceController.container.viewContext)
        }
    }
}
