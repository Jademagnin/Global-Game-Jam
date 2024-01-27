type File = {
    name: string
    path?: string
    comment?: string
}

type Application = File & {
    type: 'application'
}

type Video = File & {
    type: 'video'
}

type Audio = File & {
    type: 'audio'
}

type Image = File & {
    type: 'image'
}

type Document = File & {
    type: 'document'
}

type Folder = {
    type: 'folder'
    name: string
    files?: Files[]
    obstacle?: 'REVERSED_MOUSE' | 'ACCELERATED_MOUSE' | 'SLOWED_MOUSE' | 'GLITCHED_MOUSE'
    comment?: string
    action?: 'OPEN_WARNING'
}

type Files = Folder | Document | Video | Audio | Image | Application

export type Schema = {
    desktop: Files[]
}