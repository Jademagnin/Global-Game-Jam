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


type ActionOpenWarnings = {
    open: 'WARNING'
}

type ActionOpenChatNarrator = {
    open: 'CHAT_NARRATOR'
    text: string
}

type Folder = {
    type: 'folder'
    name: string
    files?: File[]
    obstacle?: 'REVERSED_MOUSE' | 'ACCELERATED_MOUSE' | 'SLOWED_MOUSE' | 'GLITCHED_MOUSE'
    comment?: string
    action?: ActionOpenWarnings | ActionOpenChatNarrator
}

type FileType = Folder | Document | Video | Audio | Image | Application

export type Schema = {
    desktop: FileType[]
    action: ActionOpenChatNarrator
}