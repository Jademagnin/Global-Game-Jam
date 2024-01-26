export type Document = {
    type: 'folder' | 'text' | 'image' | 'audio' | 'video'
    name: string
    content?: string | Document[]
}

export type Schema = {
    window: Document[]
}